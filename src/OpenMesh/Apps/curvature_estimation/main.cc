#include <iostream>
#include <vector>
#include <deque>
#include <typeinfo>
#include <set>
#include <cstdlib>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/PolyMeshT.hh>
#include <imgui/imgui.h>
#include <igl/opengl/glfw/imgui/ImGuiMenu.h>
#include <igl/opengl/glfw/imgui/ImGuiHelpers.h>
#include <igl/avg_edge_length.h>
#include <igl/gaussian_curvature.h>
#include <igl/principal_curvature.h>
#include <igl/massmatrix.h>
#include <igl/invert_diag.h>
#include <igl/readOFF.h>
#include <igl/opengl/glfw/Viewer.h>
#include <igl/jet.h>
#include <igl/pinv.h>
#include <Eigen/Eigenvalues>
#include <Eigen/QR>
#include <string>
#include <iostream>


using namespace Eigen;
using namespace std;

// ----------------------------------------------------------------------------
typedef OpenMesh::PolyMesh_ArrayKernelT<> _Mesh;
typedef OpenMesh::Vec3d v3d_t;
typedef vector<v3d_t> vv3d_t;
// ----------------------------------------------------------------------------
// Build a simple cube and write it to std::cout
bool is_visible = false;
bool is_visible_offset = false;
bool is_visible_vert = false;

void view_f_normals(_Mesh mesh_in, MatrixXd PD, MatrixXd f_centers) {
    mesh_in.triangulate();
    MatrixXd V;
    MatrixXi F;

    V.resize(mesh_in.n_vertices(), 3);
    F.resize(mesh_in.n_faces(), 3);

    for (size_t i = 0; i < mesh_in.n_vertices(); ++i) {
        auto p = mesh_in.point(mesh_in.vertex_handle(i));
        V(i, 0) = p[0];
        V(i, 1) = p[1];
        V(i, 2) = p[2];
    }

    for (size_t i = 0; i < mesh_in.n_faces(); ++i) {
        auto fh = mesh_in.face_handle(i);
        int vi = 0;
        for (_Mesh::ConstFaceVertexCCWIter fvi = mesh_in.cfv_ccwbegin(fh); fvi != mesh_in.cfv_ccwend(fh); ++fvi) {
//            cout << vi << " " << endl;
            F(i, vi) = fvi->idx();
            vi++;
        }
//        cout << endl;
    }

    // Plot the mesh_in with pseudocolors
    igl::opengl::glfw::Viewer viewer;
    igl::opengl::glfw::imgui::ImGuiMenu menu;
    viewer.plugins.push_back(&menu);
    // Customize the menu
    double doubleVariable = 0.1f; // Shared between two menus
    // Add content to the default menu windowOh
    menu.callback_draw_viewer_menu = [&]() {
        // Draw parent menu content
        menu.draw_viewer_menu();

        // Add new group
        if (ImGui::CollapsingHeader("New Group", ImGuiTreeNodeFlags_DefaultOpen)) {
            // Expose variable directly ...
            ImGui::InputDouble("double", &doubleVariable, 0, 0, "%.4f");

            // ... or using a custom callback
            static bool boolVariable = true;
            if (ImGui::Checkbox("bool", &boolVariable)) {
                // do something
                cout << "boolVariable: " << boolalpha << boolVariable << endl;
            }

            // Expose an enumeration type
            enum Orientation {
                Up = 0, Down, Left, Right
            };
            static Orientation dir = Up;
            ImGui::Combo("Direction", (int *) (&dir), "Up\0Down\0Left\0Right\0\0");

            // We can also use a vector<string> defined dynamically
            static int num_choices = 3;
            static vector<string> choices;
            static int idx_choice = 0;
            if (ImGui::InputInt("Num letters", &num_choices)) {
                num_choices = max(1, min(26, num_choices));
            }
            if (num_choices != (int) choices.size()) {
                choices.resize(num_choices);
                for (int i = 0; i < num_choices; ++i)
                    choices[i] = string(1, 'A' + i);
                if (idx_choice >= num_choices)
                    idx_choice = num_choices - 1;
            }
            ImGui::Combo("Letter", &idx_choice, choices);

            // Add a button
            if (ImGui::Button("Print Hello", ImVec2(-1, 0))) {
                cout << "Hello\n";
            }
        }
    };

    viewer.data(0).set_mesh(V, F);

    // for showing the direction of normals.
    const RowVector3d red(0.8, 0.2, 0.2);
    const RowVector3d blue(0.2, 0.4, 0.87);
    // Average edge length for sizing
    const double avg = igl::avg_edge_length(V, F);
    cout << avg << "the avg is " << endl;  //testing the length

    viewer.data(0).add_edges(f_centers + PD * avg, f_centers - PD * avg, red);
    viewer.launch();
}

void view_v_normal(_Mesh mesh_in, MatrixXd PD) {
    mesh_in.triangulate();
    MatrixXd V;
    MatrixXi F;

    V.resize(mesh_in.n_vertices(), 3);
    F.resize(mesh_in.n_faces(), 3);

    for (size_t i = 0; i < mesh_in.n_vertices(); ++i) {
        auto p = mesh_in.point(mesh_in.vertex_handle(i));
        V(i, 0) = p[0];
        V(i, 1) = p[1];
        V(i, 2) = p[2];
    }

    for (size_t i = 0; i < mesh_in.n_faces(); ++i) {
        auto fh = mesh_in.face_handle(i);
        int vi = 0;
        for (_Mesh::ConstFaceVertexCCWIter fvi = mesh_in.cfv_ccwbegin(fh); fvi != mesh_in.cfv_ccwend(fh); ++fvi) {
            F(i, vi) = fvi->idx();
            vi++;
        }
    }

    // Plot the mesh_in with pseudocolors
    igl::opengl::glfw::Viewer viewer;
    igl::opengl::glfw::imgui::ImGuiMenu menu;
    viewer.plugins.push_back(&menu);
    // Customize the menu
    double doubleVariable = 0.1f; // Shared between two menus
    // Add content to the default menu windowOh
    menu.callback_draw_viewer_menu = [&]() {
        // Draw parent menu content
        menu.draw_viewer_menu();

        // Add new group
        if (ImGui::CollapsingHeader("New Group", ImGuiTreeNodeFlags_DefaultOpen)) {
            // Expose variable directly ...
            ImGui::InputDouble("double", &doubleVariable, 0, 0, "%.4f");

            // ... or using a custom callback
            static bool boolVariable = true;
            if (ImGui::Checkbox("bool", &boolVariable)) {
                // do something
                cout << "boolVariable: " << boolalpha << boolVariable << endl;
            }

            // Expose an enumeration type
            enum Orientation {
                Up = 0, Down, Left, Right
            };
            static Orientation dir = Up;
            ImGui::Combo("Direction", (int *) (&dir), "Up\0Down\0Left\0Right\0\0");

            // We can also use a vector<string> defined dynamically
            static int num_choices = 3;
            static vector<string> choices;
            static int idx_choice = 0;
            if (ImGui::InputInt("Num letters", &num_choices)) {
                num_choices = max(1, min(26, num_choices));
            }
            if (num_choices != (int) choices.size()) {
                choices.resize(num_choices);
                for (int i = 0; i < num_choices; ++i)
                    choices[i] = string(1, 'A' + i);
                if (idx_choice >= num_choices)
                    idx_choice = num_choices - 1;
            }
            ImGui::Combo("Letter", &idx_choice, choices);

            // Add a button
            if (ImGui::Button("Print Hello", ImVec2(-1, 0))) {
                cout << "Hello\n";
            }
        }
    };

    viewer.data(0).set_mesh(V, F);

    // for showing the direction of normals.
    const RowVector3d red(0.8, 0.2, 0.2);
    const RowVector3d blue(0.2, 0.4, 0.87);
    // Average edge length for sizing
    const double avg = igl::avg_edge_length(V, F);
    cout << avg << "the avg is " << endl;  //testing the length

    viewer.data(0).add_edges(V + PD * avg, V - PD * avg, red);
    viewer.launch();
}

void triangle(_Mesh mesh_in, MatrixXi *F) {
    F->resize(mesh_in.n_faces() * 2, 3);

    int count = 0;
    int fcount = 0;
    for (auto f_it = mesh_in.faces_begin(); f_it != mesh_in.faces_end(); f_it++) { // face
        int vidx = 0;
        int first=0;
        int second=0;
        for (auto fh_it = mesh_in.fv_iter(*f_it); fh_it.is_valid(); ++fh_it) {
            if(vidx != 3)
            {
                (F->row(f_it->idx()*2))(first) = fh_it->idx();
                first++;
            }


            if(vidx != 1) {
                (F->row(f_it->idx()*2+1))(second) = fh_it->idx();
                second++;
            }
            vidx++;
        }
        fcount += 2;
    }
}

//void black_rec(_Mesh mesh_in, MatrixXd *V, MatrixXi *F) {
//    V->resize(mesh_in.n_vertices(), 3);
//    F->resize(mesh_in.n_faces() * 2, 3);
//
//    int count = 0;
//    int fcount = 0;
//    for (auto f_it = mesh_in.faces_begin(); f_it != mesh_in.faces_end(); f_it++) { // face
//        int vidx = 0;
//        int first=0;
//        int second=0;
//        for (auto fh_it = mesh_in.fh_iter(*f_it); fh_it.is_valid(); ++fh_it) {
//            auto vert_idx = (mesh_in.to_vertex_handle(*fh_it)).idx();
//            (*V)(vert_idx, 0) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[0] +
//                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[0]) / 2;
//            (*V)(vert_idx, 1) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[1] +
//                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[1]) / 2;
//            (*V)(vert_idx, 2) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[2] +
//                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[2]) / 2;
//            count++;
//
//            if(vidx != 3)
//            {
//                (F->row(fcount))(first) = vert_idx;
//                first++;
//            }
//
//
//            if(vidx != 1) {
//                (F->row(fcount+1))(second) = vert_idx;
//                second++;
//            }
//            vidx++;
//        }
//        fcount += 2;
//    }
//}


void black_rec(_Mesh mesh_in, MatrixXd *V, MatrixXi *F) {
    V->resize(mesh_in.n_faces() * 4, 3);
    F->resize(mesh_in.n_faces() * 2, 3);

    int count = 0;
    int fcount = 0;
    for (auto f_it = mesh_in.faces_begin(); f_it != mesh_in.faces_end(); f_it++) { // face
        for (auto fh_it = mesh_in.fh_iter(*f_it); fh_it.is_valid(); ++fh_it) {
            (*V)(count, 0) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[0] +
                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[0]) / 2;
            (*V)(count, 1) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[1] +
                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[1]) / 2;
            (*V)(count, 2) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[2] +
                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[2]) / 2;
            count++;
        }
        auto idx_base = fcount * 2;
        F->row(fcount) << idx_base, idx_base + 1, idx_base + 2;
        F->row(++fcount) << idx_base, idx_base + 2, idx_base + 3;
        fcount++;
    }
}

void offset_black_rec(_Mesh mesh_in, MatrixXd f_normals, MatrixXd *V, MatrixXi *F) {
    V->resize(mesh_in.n_faces() * 4, 3);
    F->resize(mesh_in.n_faces() * 2, 3);

    int count = 0;
    int fcount = 0;
    for (auto f_it = mesh_in.faces_begin(); f_it != mesh_in.faces_end(); f_it++) { // face
        for (auto fh_it = mesh_in.fh_iter(*f_it); fh_it.is_valid(); ++fh_it) {
            (*V)(count, 0) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[0] +
                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[0]) / 2 +
                             f_normals.row(f_it->idx())[0];
            (*V)(count, 1) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[1] +
                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[1]) / 2 +
                             f_normals.row(f_it->idx())[1];
            (*V)(count, 2) = ((mesh_in.point(mesh_in.to_vertex_handle(*fh_it)))[2] +
                              (mesh_in.point(mesh_in.from_vertex_handle(*fh_it)))[2]) / 2 +
                             f_normals.row(f_it->idx())[2];
            count++;
        }
        auto idx_base = fcount * 2;
        F->row(fcount) << idx_base, idx_base + 1, idx_base + 2;
        F->row(++fcount) << idx_base, idx_base + 2, idx_base + 3;
        fcount++;
    }
}

void offset_black_v_normals(MatrixXd Vorig, MatrixXi Forig, MatrixXd v_normals, MatrixXd *V, MatrixXi *F) {
    V->resize(Vorig.rows(), 3);
    F->resize(Forig.rows(), 3);

    *V = Vorig - v_normals;
    *F = Forig;
}

// mesh_in, init_v_normals, v_normals, f_centers, f_normals, v_normals, gaussian_curvatures, mean_curvatures
void view_total_info(_Mesh mesh_in, MatrixXd init_v_normals, MatrixXd v_normals, MatrixXd f_centers,
                     MatrixXd f_normals, MatrixXd gaussian_curvatures, MatrixXd mean_curvatures,
                     MatrixXd pc1, MatrixXd pc2) {
    igl::opengl::glfw::Viewer viewer;
    viewer.data().line_width = 4.0; //line width

    // for showing the direction of normals.
    const RowVector3d red(0.8, 0.2, 0.2);
    const RowVector3d blue(0, 1, 0);
    const RowVector3d black(0, 0, 0);
    MatrixXd to_vert, from_vert;
    to_vert.resize(mesh_in.n_vertices() * 4, 3);
    from_vert.resize(mesh_in.n_vertices() * 4, 3);

    // for offsetting the faces and balck rec
    MatrixXd Vinner, Voffset, Vvert;
    MatrixXi Finner, Foffset, Fvert;
    black_rec(mesh_in, &Vinner, &Finner);
    offset_black_rec(mesh_in, f_normals, &Voffset, &Foffset);

    // for showing quad mesh
    MatrixXi F;
    triangle(mesh_in, &F);
//    mesh_in.triangulate();
    MatrixXd V;
//    MatrixXi F;
    V.resize(mesh_in.n_vertices(), 3);
//    F.resize(mesh_in.n_faces(), 3);

    for (size_t i = 0; i < mesh_in.n_vertices(); ++i) {
        auto p = mesh_in.point(mesh_in.vertex_handle(i));
        V(i, 0) = p[0];
        V(i, 1) = p[1];
        V(i, 2) = p[2];
    }


    // offset
    offset_black_v_normals(V, F, v_normals, &Vvert, &Fvert);

    // Plot the mesh_in with pseudocolors
    // Average edge length for sizing
    const double avg = igl::avg_edge_length(V, F);
//    cout << avg << "the avg is " << endl;  //testing the length

    // set mesh and add edges. multi-layer drawing,
    // by concealing the trangle mesh (cancle the wireframe) we will show the the quad mesh in the higher layer
    // show everything we have step by step by pressing different keys
    // default. initial v_normal and optimized v_normal
    // 1. show black midpoint division
    // 2. show face normals.
    // 3. show offset faces.
    // 4. curvatures of face guassian
    // 5. mean curvatures.

    viewer.data(0).set_mesh(V, F);
//    viewer.data(0).add_edges(from_vert, to_vert, black);
    viewer.data(0).add_edges(V, V - init_v_normals * avg, red);
    viewer.data(0).add_edges(V, V - v_normals * avg, blue);
    viewer.append_mesh(false);
    viewer.append_mesh(false);
    viewer.append_mesh(false);
    viewer.append_mesh(false);
    viewer.append_mesh(false);
    viewer.append_mesh(false);

    // cout<< "vinner"<<Vinner <<endl<< "Finner"<<Finner<<endl;  // bebuging
    viewer.data_list[1].set_mesh(Vinner, Finner);  // show black
//    viewer.data_list[2].set_mesh(Voffset, Foffset);
    viewer.data_list[2].set_mesh(V, F);
    viewer.data_list[2].add_edges(f_centers + f_normals * avg, f_centers - f_normals * avg, black);
    viewer.data_list[3].set_mesh(Vvert, Fvert);

    viewer.data_list[4].set_mesh(V, F);
    MatrixXd C;
    igl::jet(gaussian_curvatures, true, C);
//    cout<<"\n---------"<<"C size is "<< C.size() << "mesh"<<mesh_in.n_vertices()<<"\n"<<C<<endl;
    viewer.data_list[4].set_colors(C);
    // cout << "Vertex size, " << V.rows() << "Face size, : " << F.rows() << endl;
    // cout << "COlor size << " <<  gaussian_curvatures.rows() << "x" << gaussian_curvatures.cols() << endl;

    viewer.data_list[5].set_mesh(V, F);
    MatrixXd mean_cur_color;
    igl::jet(mean_curvatures, true, mean_cur_color);
    viewer.data_list[5].set_colors(mean_cur_color);

    viewer.data_list[6].set_mesh(V, F);
    viewer.data_list[6].add_edges(f_centers + 1.2*pc1 * avg, f_centers - 1.2*pc1 * avg, red);
    viewer.data_list[6].add_edges(f_centers + 1.2*pc2 * avg, f_centers - 1.2*pc2 * avg, blue);
    viewer.data(6).line_width = 3.0; //line width

    viewer.selected_data_index = 0;
    viewer.callback_key_down =
            [&](igl::opengl::glfw::Viewer &, unsigned int key, int mod) {
                if (key == GLFW_KEY_0) {
                    cout << "got 0" << endl;
                    viewer.data(1).set_visible(false);
                    viewer.data(2).set_visible(false);
                    viewer.data(3).set_visible(false);
                    viewer.data(4).set_visible(false);
                    viewer.data(5).set_visible(false);
                    viewer.data(0).set_visible(true);
                    return true;
                }

                if (key == GLFW_KEY_1) {
                    cout << "got 1" << endl;
                    int old_id = viewer.data().id;
                    cout << old_id << endl;
                    cout << "selected idx " << viewer.selected_data_index << endl;
                    viewer.selected_data_index = 1;
                    viewer.data_list[viewer.selected_data_index].set_colors(RowVector3d(0.1, 0.1, 0.9));
                    is_visible = !is_visible;
                    viewer.data(viewer.selected_data_index).set_visible(is_visible);
                    return true;
                }
                else if (key == GLFW_KEY_SPACE)
                {
                    viewer.selected_data_index = (viewer.selected_data_index+1) %6;
                    return true;
                }
                else if (key == GLFW_KEY_ENTER)
                {
                    is_visible = !is_visible;
                    viewer.data(0).set_visible(is_visible);
                    return true;
                }

                else if (key == GLFW_KEY_2) {
                    cout << "got enter" << endl;
                    is_visible_offset = !is_visible_offset;
                    viewer.data(2).set_visible(!is_visible_offset);
                    viewer.data(0).set_visible(false);
                    return true;
                } else if (key == GLFW_KEY_3) {
                    // close 1
                    viewer.selected_data_index = 0;
                    viewer.data(viewer.selected_data_index).set_visible(true);

                    cout << "got 3" << endl;
                    int old_id = viewer.data().id;
                    cout << old_id << endl;
                    cout << "selected idx " << viewer.selected_data_index << endl;

                    viewer.selected_data_index = 3;
                    viewer.data_list[viewer.selected_data_index].set_colors(RowVector3d(0.8, 0.5, 0.9));
                    is_visible_vert = !is_visible_vert;
                    viewer.data(viewer.selected_data_index).set_visible(is_visible_vert);
                    return true;
                } else if (key == GLFW_KEY_4) {
                    cout << "got 4" << endl;
                    int old_id = viewer.data().id;
                    cout << old_id << endl;
                    cout << "selected idx " << viewer.selected_data_index << endl;
                    viewer.selected_data_index = 4;
                    is_visible_offset = !is_visible_offset;
                    viewer.data(viewer.selected_data_index).set_visible(!is_visible_offset);

                    // close 0
                    viewer.selected_data_index = 0;
                    viewer.data(viewer.selected_data_index).set_visible(false);
                    return true;
                } else if (key == GLFW_KEY_5) {
                    cout << "got 5" << endl;
                    viewer.selected_data_index = 5;
                    is_visible_offset = !is_visible_offset;
                    viewer.data(viewer.selected_data_index).set_visible(!is_visible_offset);

                    // close 0
                    viewer.selected_data_index = 0;
                    viewer.data(viewer.selected_data_index).set_visible(false);
                    return true;
                }
                else if (key == GLFW_KEY_6) {
                    cout << "got 6" << endl;
                    viewer.selected_data_index = 6;
                    is_visible_offset = !is_visible_offset;
                    viewer.data(viewer.selected_data_index).set_visible(!is_visible_offset);

                    // close 0
                    viewer.selected_data_index = 0;
                    viewer.data(viewer.selected_data_index).set_visible(false);
                    return true;

                }
                return false;
            };

    igl::opengl::glfw::imgui::ImGuiMenu menu;
    viewer.plugins.push_back(&menu);
    // Customize the menu
    double doubleVariable = 0.1f; // Shared between two menus
    // Add content to the default menu windowOh
    menu.callback_draw_viewer_menu = [&]() {
        // Draw parent menu content
        menu.draw_viewer_menu();
        // Add new group
        if (ImGui::CollapsingHeader("New Group", ImGuiTreeNodeFlags_DefaultOpen)) {
            // Expose variable directly ...
            ImGui::InputDouble("double", &doubleVariable, 0, 0, "%.4f");

            // ... or using a custom callback
            static bool boolVariable = true;
            if (ImGui::Checkbox("bool", &boolVariable)) {
                // do something
                cout << "boolVariable: " << boolalpha << boolVariable << endl;
            }

            // Expose an enumeration type
            enum Orientation {
                Up = 0, Down, Left, Right
            };
            static Orientation dir = Up;
            ImGui::Combo("Direction", (int *) (&dir), "Up\0Down\0Left\0Right\0\0");

            // We can also use a vector<string> defined dynamically
            static int num_choices = 3;
            static vector<string> choices;
            static int idx_choice = 0;
            if (ImGui::InputInt("Num letters", &num_choices)) {
                num_choices = max(1, min(26, num_choices));
            }
            if (num_choices != (int) choices.size()) {
                choices.resize(num_choices);
                for (int i = 0; i < num_choices; ++i)
                    choices[i] = string(1, 'A' + i);
                if (idx_choice >= num_choices)
                    idx_choice = num_choices - 1;
            }
            ImGui::Combo("Letter", &idx_choice, choices);

            // Add a button
            if (ImGui::Button("Print Hello", ImVec2(-1, 0))) {
                cout << "Hello\n";
            }
        }
    };

    viewer.launch();
}


template<class MatT>
Eigen::Matrix<typename MatT::Scalar, MatT::ColsAtCompileTime, MatT::RowsAtCompileTime>
pseudoinverse(const MatT &mat, typename MatT::Scalar tolerance = typename MatT::Scalar{1e-7}) // choose appropriately
{
    typedef typename MatT::Scalar Scalar;
    auto svd = mat.jacobiSvd(Eigen::ComputeFullU | Eigen::ComputeFullV);
    const auto &singularValues = svd.singularValues();
    Eigen::Matrix<Scalar, MatT::ColsAtCompileTime, MatT::RowsAtCompileTime> singularValuesInv(mat.cols(), mat.rows());
    singularValuesInv.setZero();
    for (unsigned int i = 0; i < singularValues.size(); ++i) {
        if (singularValues(i) > tolerance) {
            singularValuesInv(i, i) = Scalar{1} / singularValues(i);
        } else {
            singularValuesInv(i, i) = Scalar{0};
        }
    }
    return svd.matrixV() * singularValuesInv * svd.matrixU().adjoint();
}

int main(int argc, char *argv[]) {
    std::cout << "Implementation of quad mesh curvature estimation via optimization" << std::endl;

    //// --------------------- read meashes
    _Mesh mesh;
    if (!OpenMesh::IO::read_mesh(mesh, "../../../model/FlyingCarpet_quad.obj")) {
        std::cerr << "read error\n";
        exit(1);
    }

    //// --------------------- normal initialize
    // initilize the normal for each vertex as the cross product of two edges.
    // which is the initial guess by normalized cross product of two edges
    vv3d_t one_ring_edges;
    vector<size_t> valence;
    v3d_t center;
    MatrixXd v_normals = MatrixXd::Zero(mesh.n_vertices(), 3);
    int n_neighbor;
    for (auto v_it = mesh.vertices_begin(); v_it != mesh.vertices_end(); v_it++) { // vertex
        center = mesh.point(*v_it);
        n_neighbor = 0;
        for (_Mesh::VertexVertexIter vv_it = mesh.vv_iter(*v_it); vv_it.is_valid(); ++vv_it) {
            auto curr = mesh.point(*vv_it);
            one_ring_edges.push_back(v3d_t(curr - center).normalized());
            n_neighbor++;
        }
        valence.push_back(one_ring_edges.size());
        if (n_neighbor > 2) {
            one_ring_edges.push_back(one_ring_edges[0]);
        }

        v3d_t normal = v3d_t(0);
        for (size_t ii = 0; ii < one_ring_edges.size() - 1; ii++) {
            normal += one_ring_edges[ii] % one_ring_edges[ii + 1]; // % is the cross product
        }
        normal /= one_ring_edges.size() - 1;
        one_ring_edges.clear();
        v_normals(v_it->idx(), 0) = normal[0];
        v_normals(v_it->idx(), 1) = normal[1];
        v_normals(v_it->idx(), 2) = normal[2];
    }

    // Now we have all the vertex normals (but just the simple guess).
    // check if v_normals is correct or not.
    // todo: why so many zeros.
//    cout << "\n-------------------" << endl << "v_normals" << endl << v_normals << "\n-------------------" << endl;
//    view_v_normal(mesh, v_normals);

    //// --------------------- face_normals, which is always the same during optimization
    // get the normal for each face using the cross product between the intercross lines of the quad.
    MatrixXd f_normals;
    MatrixXd f_centers;
    f_normals.resize(mesh.n_faces(), 3);
    f_centers.resize(mesh.n_faces(), 3);
    vv3d_t quad_vertices;
    for (auto f_it = mesh.faces_begin(); f_it != mesh.faces_end(); f_it++) { // face
        for (auto fv_it = mesh.fv_iter(*f_it); fv_it.is_valid(); ++fv_it) {
            quad_vertices.push_back(v3d_t(mesh.point(*fv_it)));
        }

        auto normal = ((quad_vertices[0] - quad_vertices[2]) %
                       (quad_vertices[1] - quad_vertices[3])).normalized();

        auto f_center = quad_vertices[2] + (quad_vertices[0] - quad_vertices[2]) / 2;
        quad_vertices.clear();

        f_normals(f_it->idx(), 0) = normal[0];
        f_normals(f_it->idx(), 1) = normal[1];
        f_normals(f_it->idx(), 2) = normal[2];

        f_centers(f_it->idx(), 0) = f_center[0];
        f_centers(f_it->idx(), 1) = f_center[1];
        f_centers(f_it->idx(), 2) = f_center[2];
    }

    //  Now we have all the vertex normals (initial guess), and face normals
    // cout << "\n-------------------" << endl << "f_normals" << endl << f_normals << "\n-------------------" << endl;
    // view_f_normals(mesh, f_normals, f_centers);

    //// ----------------------- lets get the face normal of the adjacent faces of each quad.
    MatrixXd adj_f_normals;
    MatrixXi edg_orders;
    adj_f_normals.resize(mesh.n_faces(), 12);
    edg_orders.resize(mesh.n_faces(), 4);
    for (auto f_it = mesh.faces_begin(); f_it != mesh.faces_end(); f_it++) { // face
        int face_count = 0;
        for (auto fh_it = mesh.fh_iter(*f_it); fh_it.is_valid(); ++fh_it) {
            edg_orders(f_it->idx(), face_count) = fh_it->idx();
            auto opposite_idx = (mesh.opposite_face_handle(*fh_it)).idx();
            if (!mesh.is_boundary(*fh_it) and opposite_idx != -1) {
                adj_f_normals(f_it->idx(), 3 * face_count) = f_normals.row(opposite_idx)(0);
                adj_f_normals(f_it->idx(), 3 * face_count + 1) = f_normals.row(opposite_idx)(1);
                adj_f_normals(f_it->idx(), 3 * face_count + 2) = f_normals.row(opposite_idx)(2);
                face_count++;
            }
        }
    }


    //  Now we have all the vertex normals, and face normals, adjacent face normals
    // cout << "\n-------------------" << endl << "edg_orders" << endl << edg_orders << "\n-------------------" << endl;
    // cout << "\n-------------------" << endl << "adjacent f_normals" << endl << adj_f_normals << "\n-------------------" << endl;

    //// ----------------- optimization, update the vertices normals, and then calculate the vertex curvatures.
    /// -> shape operator -> egien value -> principal curvatures
    // for 12 constraints
    // MatrixXd lin_sys_a = MatrixXd::Zero(12, 12);
    // VectorXd lin_sys_b; lin_sys_b.resize(12, 1);
    // lin_sys_b << 2.0 ,  2.0 ,  2.0 ,  0 ,  2.0 ,  2.0 ,  2.0 ,  2.0, 0.0, 0.0, 0.0, 0.0;
    // for 16 constraints (over constraint, default)

    MatrixXd lin_sys_a = MatrixXd::Zero(16, 12);
    VectorXd lin_sys_b;
    lin_sys_b.resize(16, 1);
    lin_sys_b << 2.0, 2.0, 2.0, 0, 2.0, 2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0;

    MatrixXd solution;

    MatrixXd init_v_normals = v_normals;
    MatrixXd new_v_normals = v_normals;
    deque<Vector3d> vertices_;
    deque<v3d_t> adj_normals;
    Vector3d f_normal;
    Vector3d of_normal; //opposite_face_normal
    MatrixXd v_normals_diff = MatrixXd::Zero(4, 3);
    MatrixXd v_normals_diff2 = MatrixXd::Zero(4, 3);
    MatrixXd opp_normals = MatrixXd::Zero(4, 3);
    int f_it_idx;
    vector<size_t> v_idx_of_face;
    v3d_t v_normal;
    set<int, greater<int>> neighbours;
    set<int, greater<int>> vtx_neighbours;

    //// optimization
    // argv is the input argument for optimization steps.
    for (int k = 0; k < atoi(argv[1]); k++) {   // optimization steps
        for (auto f_it = mesh.faces_begin(); f_it != mesh.faces_end(); f_it++) { // faces
            f_it_idx = f_it->idx();
            //  cout << "=====> curr_face " << f_it_idx << "/" << mesh.n_faces() << endl;
            for (size_t ii = 0; ii < 4; ii++) {  // number of edges of each face is 4
                int e = edg_orders(f_it_idx, ii);   // handle No. of edge
                auto edge = mesh.halfedge_handle(e);    // half edge handle
                auto v_from = mesh.from_vertex_handle(edge);    // v_from handle
                auto f_idx = mesh.face_handle(edge);

                f_normal = f_normals.row(f_idx.idx());
                // get the opposite face normals, when there is a boundary (no adj face), of_normal will be zero
                of_normal(0) = adj_f_normals.row(f_it_idx)(ii * 3);
                of_normal(1) = adj_f_normals.row(f_it_idx)(ii * 3 + 1);
                of_normal(2) = adj_f_normals.row(f_it_idx)(ii * 3 + 2);

                v_idx_of_face.push_back(v_from.idx());  // 4 vertices of a face
                auto vtx = mesh.point(v_from);
                // get 4 vertices and 4 adj_normals
                vertices_.push_back(Vector3d(vtx[0], vtx[1], vtx[2]));
                adj_normals.push_back(v3d_t(of_normal(0), of_normal(1), of_normal(2)));

                //// this part is a little bit confusing at the first time,
                /// this is for getting the vertice v_j along the same line of v.
                // get the neighbors of vertex on the inside and outside
                // indexed properly. so that we get the constraints on the vertex normals
                // in the two PC directions
                // for opp face, add vtx
                //for curr face add vtx
                // find out = set\curr_vtx_neigh
                //pair is out, mesh.from(he)
                auto opposite_fidx = mesh.opposite_face_handle(edge);
                auto curr_fidx = mesh.face_handle(edge);
                int opp_vtx_idx, in_vtx_idx;
                if (!mesh.is_boundary(edge) and opposite_fidx.idx() != -1) {
                    for (auto curr_fvit = mesh.fv_iter(opposite_fidx); curr_fvit.is_valid(); ++curr_fvit) {
                        neighbours.insert(curr_fvit->idx());
                    }
                }
 
                if (!mesh.is_boundary(edge) and curr_fidx.idx() != -1) {
                    for (auto curr_fvit = mesh.fv_iter(curr_fidx); curr_fvit.is_valid(); ++curr_fvit) {
                        neighbours.insert(curr_fvit->idx());
                    }
                }

                for (auto vv_it = mesh.vv_iter(v_from); vv_it.is_valid(); ++vv_it) {
                    vtx_neighbours.insert(vv_it->idx());
                }

                // you may have nothing here.
                for (auto jj: vtx_neighbours) {
                    if (!neighbours.count(jj)) {
                        opp_vtx_idx = jj;
                        in_vtx_idx = mesh.to_vertex_handle(edge).idx();
//                        in_vtx_idx = v_from.idx();
                        v_normals_diff(ii, 0) = v_normals(opp_vtx_idx, 0) - v_normals(in_vtx_idx, 0);
                        v_normals_diff(ii, 1) = v_normals(opp_vtx_idx, 1) - v_normals(in_vtx_idx, 1);
                        v_normals_diff(ii, 2) = v_normals(opp_vtx_idx, 2) - v_normals(in_vtx_idx, 2);
                    }
                }

                // find the second pair. If not exists, zeros
                neighbours.clear(); // do not clear vtx_neighbours, we will use them.
                if (ii == 0) { e = edg_orders(f_it_idx, 3); }
                else { e = edg_orders(f_it_idx, ii - 1); }

                //// todo: the only thing missing is error checking in the edg order function as sometiomes the edge handles are useless when the edge to visit is a boundary edge
                // if (e >= mesh.n_halfedges() || e < 0 ){
                //     continue;
                // }

                edge = mesh.halfedge_handle(e);
                opposite_fidx = mesh.opposite_face_handle(edge);
                if (!mesh.is_boundary(edge) and opposite_fidx.idx() != -1) {
                    for (auto curr_fvit = mesh.fv_iter(opposite_fidx); curr_fvit.is_valid(); ++curr_fvit) {
                        neighbours.insert(curr_fvit->idx());
                    }
                }

                if (!mesh.is_boundary(edge) and curr_fidx.idx() != -1) {
                    for (auto curr_fvit = mesh.fv_iter(curr_fidx); curr_fvit.is_valid(); ++curr_fvit) {
                        neighbours.insert(curr_fvit->idx());
                    }
                }


                for (auto jj: vtx_neighbours) {
                    if (!neighbours.count(jj)) {
                        opp_vtx_idx = jj;
                        in_vtx_idx = mesh.to_vertex_handle(edge).idx();
                        v_normals_diff2(ii, 0) = v_normals(opp_vtx_idx, 0) - v_normals(in_vtx_idx, 0);
                        v_normals_diff2(ii, 1) = v_normals(opp_vtx_idx, 1) - v_normals(in_vtx_idx, 1);
                        v_normals_diff2(ii, 2) = v_normals(opp_vtx_idx, 2) - v_normals(in_vtx_idx, 2);

                        // below is for another method, keep it.
                        //v_normal[0] = v_normals(opp_vtx_idx, 0);
                        //v_normal[1] = v_normals(opp_vtx_idx, 1);
                        //v_normal[2] = v_normals(opp_vtx_idx, 2);
                        //opp_normals(ii) = 2- of_normal % v_normal;
                    }
                }
            }

            /// now we build the linear system and solve it. Here we construct A and b matrix one by one element-wise
            /// Black-rectangle constraints
            lin_sys_a(0, 0) = f_normal[0];
            lin_sys_a(0, 1) = f_normal[1];
            lin_sys_a(0, 2) = f_normal[2];
            lin_sys_a(0, 3) = f_normal[0];
            lin_sys_a(0, 4) = f_normal[1];
            lin_sys_a(0, 5) = f_normal[2];

            lin_sys_a(1, 3) = f_normal[0];
            lin_sys_a(1, 4) = f_normal[1];
            lin_sys_a(1, 5) = f_normal[2];
            lin_sys_a(1, 6) = f_normal[0];
            lin_sys_a(1, 7) = f_normal[1];
            lin_sys_a(1, 8) = f_normal[2];

            lin_sys_a(2, 6) = f_normal[0];
            lin_sys_a(2, 7) = f_normal[1];
            lin_sys_a(2, 8) = f_normal[2];
            lin_sys_a(2, 9) = f_normal[0];
            lin_sys_a(2, 10) = f_normal[1];
            lin_sys_a(2, 11) = f_normal[2];

            /// Shape operator constraint
            auto v13 = vertices_[1] - vertices_[3];
            auto v20 = vertices_[2] - vertices_[0];
            lin_sys_a(3, 0) = v13[0];
            lin_sys_a(3, 1) = v13[1];
            lin_sys_a(3, 2) = v13[2];
            lin_sys_a(3, 3) = v20[0];
            lin_sys_a(3, 4) = v20[1];
            lin_sys_a(3, 5) = v20[2];
            lin_sys_a(3, 6) = -v13[0];
            lin_sys_a(3, 7) = -v13[1];
            lin_sys_a(3, 8) = -v13[2];
            lin_sys_a(3, 9) = -v20[0];
            lin_sys_a(3, 10) = -v20[1];
            lin_sys_a(3, 11) = -v20[2];

            /// Adjacent face constraints
            lin_sys_a(4, 0) = adj_normals[0][0];
            lin_sys_a(4, 1) = adj_normals[0][1];
            lin_sys_a(4, 2) = adj_normals[0][2];
            lin_sys_a(4, 3) = adj_normals[0][0];
            lin_sys_a(4, 4) = adj_normals[0][1];
            lin_sys_a(4, 5) = adj_normals[0][2];

            lin_sys_a(5, 3) = adj_normals[1][0];
            lin_sys_a(5, 4) = adj_normals[1][1];
            lin_sys_a(5, 5) = adj_normals[1][2];
            lin_sys_a(5, 6) = adj_normals[1][0];
            lin_sys_a(5, 7) = adj_normals[1][1];
            lin_sys_a(5, 8) = adj_normals[1][2];

            lin_sys_a(6, 6) = adj_normals[2][0];
            lin_sys_a(6, 7) = adj_normals[2][1];
            lin_sys_a(6, 8) = adj_normals[2][2];
            lin_sys_a(6, 9) = adj_normals[2][0];
            lin_sys_a(6, 10) = adj_normals[2][1];
            lin_sys_a(6, 11) = adj_normals[2][2];

            lin_sys_a(7, 0) = adj_normals[3][0];
            lin_sys_a(7, 1) = adj_normals[3][1];
            lin_sys_a(7, 2) = adj_normals[3][2];
            lin_sys_a(7, 9) = adj_normals[3][0];
            lin_sys_a(7, 10) = adj_normals[3][1];
            lin_sys_a(7, 11) = adj_normals[3][2];

            /// Adjacent face constraints. This is for the second method, have not finished
            // lin_sys_a(8, 0) = opp_normals[0][0];
            // lin_sys_a(8, 1) = adj_normals[0][1];
            // lin_sys_a(8, 2) = adj_normals[0][2];
            // lin_sys_a(8, 3) = adj_normals[0][0];
            // lin_sys_a(8, 4) = adj_normals[0][1];
            // lin_sys_a(8, 5) = adj_normals[0][2];

            /// gordon's inline constraint
            lin_sys_a(8, 0) = v_normals_diff(0, 0);
            lin_sys_a(8, 1) = v_normals_diff(0, 1);
            lin_sys_a(8, 2) = v_normals_diff(0, 2);

            lin_sys_a(9, 3) = v_normals_diff(1, 0);
            lin_sys_a(9, 4) = v_normals_diff(1, 1);
            lin_sys_a(9, 5) = v_normals_diff(1, 2);

            lin_sys_a(10, 6) = v_normals_diff(2, 0);
            lin_sys_a(10, 7) = v_normals_diff(2, 1);
            lin_sys_a(10, 8) = v_normals_diff(2, 2);

            lin_sys_a(11, 9) = v_normals_diff(3, 0);
            lin_sys_a(11, 10) = v_normals_diff(3, 1);
            lin_sys_a(11, 11) = v_normals_diff(3, 2);

            lin_sys_a(12, 0) = v_normals_diff2(0, 0);
            lin_sys_a(12, 1) = v_normals_diff2(0, 1);
            lin_sys_a(12, 2) = v_normals_diff2(0, 2);

            lin_sys_a(13, 3) = v_normals_diff2(1, 0);
            lin_sys_a(13, 4) = v_normals_diff2(1, 1);
            lin_sys_a(13, 5) = v_normals_diff2(1, 2);

            lin_sys_a(14, 6) = v_normals_diff2(2, 0);
            lin_sys_a(14, 7) = v_normals_diff2(2, 1);
            lin_sys_a(14, 8) = v_normals_diff2(2, 2);

            lin_sys_a(15, 9) = v_normals_diff2(3, 0);
            lin_sys_a(15, 10) = v_normals_diff2(3, 1);
            lin_sys_a(15, 11) = v_normals_diff2(3, 2);

            solution = lin_sys_a.colPivHouseholderQr().solve(lin_sys_b);

            /// now we get the new local v_normals : solution.
            new_v_normals(v_idx_of_face[0], 0) = solution(0);
            new_v_normals(v_idx_of_face[0], 1) = solution(1);
            new_v_normals(v_idx_of_face[0], 2) = solution(2);
            new_v_normals(v_idx_of_face[1], 0) = solution(3);
            new_v_normals(v_idx_of_face[1], 1) = solution(4);
            new_v_normals(v_idx_of_face[1], 2) = solution(5);
            new_v_normals(v_idx_of_face[2], 0) = solution(6);
            new_v_normals(v_idx_of_face[2], 1) = solution(7);
            new_v_normals(v_idx_of_face[2], 2) = solution(8);
            new_v_normals(v_idx_of_face[3], 0) = solution(9);
            new_v_normals(v_idx_of_face[3], 1) = solution(10);
            new_v_normals(v_idx_of_face[3], 2) = solution(11);

            // cout << "\t\tRelative error " << (lin_sys_a * solution - lin_sys_b).norm() / lin_sys_b.norm() << endl;

            v_idx_of_face.clear();
            adj_normals.clear();
            // lin_sys_a = MatrixXd::Zero(12, 12); // this is for the second method, comgaussian_curvaturesment it if not used.
            lin_sys_a = MatrixXd::Zero(16, 12);
            neighbours.clear();
            vtx_neighbours.clear();
            v_normals_diff = MatrixXd::Zero(4, 3);
        }
        v_normals = v_normals + 0.001 * new_v_normals;  /// important. The step size is 0.001
    }

    /// Now we have everthing.
    /// calculate curvatures locally by solving the local shape operator and get its egenvalues.
    MatrixXd lin_sys_v = MatrixXd::Zero(2, 3);  // vertices corrdinates
    MatrixXd lin_sys_n = MatrixXd::Zero(2, 3);  // v_normals.
    MatrixXd shape_operator = MatrixXd::Zero(2, 2);
    vector<RowVector3d> quad_v_normals;
    quad_vertices.clear(); // we use the quad_vertices defined before.

    MatrixXd curvature = MatrixXd::Zero(1, 2); //local curvature
    MatrixXd principle_vector = MatrixXd::Zero(2, 2);
    MatrixXd gaussian_curvatures = MatrixXd::Zero(mesh.n_faces()*2, 1); // we have to change to traingle.
    MatrixXd mean_curvatures = MatrixXd::Zero(mesh.n_faces()*2, 1);
    MatrixXd pc1 = MatrixXd::Zero(mesh.n_faces(), 3);
    MatrixXd pc2 = MatrixXd::Zero(mesh.n_faces(), 3);
    MatrixXd coor_trans = MatrixXd::Zero(3, 3);

    for (auto f_it = mesh.faces_begin(); f_it != mesh.faces_end(); f_it++) { // face
        for (auto fv_it = mesh.fv_iter(*f_it); fv_it.is_valid(); ++fv_it) {  // v
            quad_vertices.push_back(v3d_t(mesh.point(*fv_it)));
            quad_v_normals.push_back(v_normals.row((fv_it->idx())));
        }
        lin_sys_v(0, 0) = quad_vertices[0][0] - quad_vertices[2][0];
        lin_sys_v(0, 1) = quad_vertices[0][1] - quad_vertices[2][1];
        lin_sys_v(0, 2) = quad_vertices[0][2] - quad_vertices[2][2];
        lin_sys_v(1, 0) = quad_vertices[1][0] - quad_vertices[3][0];
        lin_sys_v(1, 1) = quad_vertices[1][1] - quad_vertices[3][1];
        lin_sys_v(1, 2) = quad_vertices[1][2] - quad_vertices[3][2];

        lin_sys_n(0, 0) = quad_v_normals[2][0] - quad_v_normals[0][0];
        lin_sys_n(0, 1) = quad_v_normals[2][1] - quad_v_normals[0][1];
        lin_sys_n(0, 2) = quad_v_normals[2][2] - quad_v_normals[0][2];
        lin_sys_n(1, 0) = quad_v_normals[3][0] - quad_v_normals[1][0];
        lin_sys_n(1, 1) = quad_v_normals[3][1] - quad_v_normals[1][1];
        lin_sys_n(1, 2) = quad_v_normals[3][2] - quad_v_normals[1][2];

        cout << "----------------\n"<<"lin_sys\n"<<lin_sys_v << endl << lin_sys_n <<endl;  //debuging
        shape_operator = lin_sys_n * pseudoinverse(lin_sys_v);
        cout << "shape operator \n"<< shape_operator<<endl;
        Eigen::SelfAdjointEigenSolver<Eigen::Matrix2d> eigensolver(shape_operator);
        if (eigensolver.info() != Eigen::Success) abort();

        curvature = eigensolver.eigenvalues();
        cout << "egienvalues \n"<< curvature<<endl;  //debuging
        principle_vector = eigensolver.eigenvectors();
        auto f_idx = f_it->idx();
        gaussian_curvatures(f_idx*2, 0) = curvature(0, 0) * curvature(1,0);
        gaussian_curvatures(f_idx*2+1, 0) = curvature(0,0) * curvature(1,0);
        mean_curvatures(f_idx*2, 0) = (curvature(0,0) + curvature(1,0)) / 2;
        mean_curvatures(f_idx*2+1, 0) = (curvature(0,0) + curvature(1,0)) / 2;

        coor_trans(0, 2) = f_normals(f_idx, 0);
        coor_trans(1, 2) = f_normals(f_idx, 1);
        coor_trans(2, 2) = f_normals(f_idx, 2);

        coor_trans(0, 0) = quad_vertices[0][0] - quad_vertices[2][0];
        coor_trans(1, 0) = quad_vertices[0][1] - quad_vertices[2][1];
        coor_trans(2, 0) = quad_vertices[0][2] - quad_vertices[2][2];

        coor_trans( 0, 1) = quad_vertices[1][0] - quad_vertices[3][0];
        coor_trans( 1, 1) = quad_vertices[1][1] - quad_vertices[3][1];
        coor_trans( 2, 1) = quad_vertices[1][2] - quad_vertices[3][2];

        pc1.row(f_idx) = coor_trans * Vector3d(principle_vector(0,0), principle_vector(1,0), 0);
        pc2.row(f_idx) = coor_trans * Vector3d(principle_vector(0,1), principle_vector(1,1), 0);

        quad_vertices.clear();
        quad_v_normals.clear();
    }
    /// curvarues.
    //cout << "\n-------------------" << endl << "guassian_curvatures" << endl << gaussian_curvatures
     //    << "\n-------------------" << endl;
    //cout << "\n-------------------" << endl << "mean_curvatures" << endl << mean_curvatures << "\n-------------------"<< endl;
    //cout << "\n-------------------" << endl << "principal direction 1"<<pc1 <<endl;
    //cout << "\n-------------------" << endl << "principal direction 2"<<pc2 <<endl;

    /// now we have the curvatures, we will show the curvatures of each vertices.
    // show everything we have step by step by pressing different keys
    // 1: face normals.
    // 2. initial v_normal and optimized v_normal
    // 3. offset faces.
    // 4. curvatures of face guassian
    // 5. mean curvatures.
    view_total_info(mesh, init_v_normals, v_normals, f_centers, f_normals, gaussian_curvatures, mean_curvatures, pc1, pc2);
    return 0;
}