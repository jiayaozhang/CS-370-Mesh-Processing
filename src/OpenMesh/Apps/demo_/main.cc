#include <iostream>
#include <vector>
#include <deque>
#include <typeinfo>
#include <set>
#include <iterator>
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
//#include "tutorial_shared_path.h"

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
    menu.callback_draw_viewer_menu = [&]()
    {
        // Draw parent menu content
        menu.draw_viewer_menu();

        // Add new group
        if (ImGui::CollapsingHeader("New Group", ImGuiTreeNodeFlags_DefaultOpen))
        {
            // Expose variable directly ...
            ImGui::InputDouble("double", &doubleVariable, 0, 0, "%.4f");

            // ... or using a custom callback
            static bool boolVariable = true;
            if (ImGui::Checkbox("bool", &boolVariable))
            {
                // do something
                cout << "boolVariable: " << boolalpha << boolVariable << endl;
            }

            // Expose an enumeration type
            enum Orientation { Up=0, Down, Left, Right };
            static Orientation dir = Up;
            ImGui::Combo("Direction", (int *)(&dir), "Up\0Down\0Left\0Right\0\0");

            // We can also use a vector<string> defined dynamically
            static int num_choices = 3;
            static vector<string> choices;
            static int idx_choice = 0;
            if (ImGui::InputInt("Num letters", &num_choices))
            {
                num_choices = max(1, min(26, num_choices));
            }
            if (num_choices != (int) choices.size())
            {
                choices.resize(num_choices);
                for (int i = 0; i < num_choices; ++i)
                    choices[i] = string(1, 'A' + i);
                if (idx_choice >= num_choices)
                    idx_choice = num_choices - 1;
            }
            ImGui::Combo("Letter", &idx_choice, choices);

            // Add a button
            if (ImGui::Button("Print Hello", ImVec2(-1,0)))
            {
                cout << "Hello\n";
            }
        }
    };

    viewer.data(0).set_mesh(V, F);

//    MatrixXd C;
//    igl::jet(K,true,C);   // K is the input vector to indicate color.
//    viewer.data(0).set_colors(C);


    // for showing the direction of normals.
    const RowVector3d red(0.8,0.2,0.2);
    const RowVector3d blue(0.2, 0.4, 0.87);
    // Average edge length for sizing
    const double avg = igl::avg_edge_length(V,F);
    cout << avg << "the avg is " << endl;  //testing the length

    viewer.data(0).add_edges(f_centers + PD*avg, f_centers - PD*avg, red);
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
    menu.callback_draw_viewer_menu = [&]()
    {
        // Draw parent menu content
        menu.draw_viewer_menu();

        // Add new group
        if (ImGui::CollapsingHeader("New Group", ImGuiTreeNodeFlags_DefaultOpen))
        {
            // Expose variable directly ...
            ImGui::InputDouble("double", &doubleVariable, 0, 0, "%.4f");

            // ... or using a custom callback
            static bool boolVariable = true;
            if (ImGui::Checkbox("bool", &boolVariable))
            {
                // do something
                cout << "boolVariable: " << boolalpha << boolVariable << endl;
            }

            // Expose an enumeration type
            enum Orientation { Up=0, Down, Left, Right };
            static Orientation dir = Up;
            ImGui::Combo("Direction", (int *)(&dir), "Up\0Down\0Left\0Right\0\0");

            // We can also use a vector<string> defined dynamically
            static int num_choices = 3;
            static vector<string> choices;
            static int idx_choice = 0;
            if (ImGui::InputInt("Num letters", &num_choices))
            {
                num_choices = max(1, min(26, num_choices));
            }
            if (num_choices != (int) choices.size())
            {
                choices.resize(num_choices);
                for (int i = 0; i < num_choices; ++i)
                    choices[i] = string(1, 'A' + i);
                if (idx_choice >= num_choices)
                    idx_choice = num_choices - 1;
            }
            ImGui::Combo("Letter", &idx_choice, choices);

            // Add a button
            if (ImGui::Button("Print Hello", ImVec2(-1,0)))
            {
                cout << "Hello\n";
            }
        }
    };

    viewer.data(0).set_mesh(V, F);

//    MatrixXd C;
//    igl::jet(K,true,C);   // K is the input vector to indicate color.
//    viewer.data(0).set_colors(C);

    // for showing the direction of normals.
    const RowVector3d red(0.8,0.2,0.2);
    const RowVector3d blue(0.2, 0.4, 0.87);
    // Average edge length for sizing
    const double avg = igl::avg_edge_length(V,F);
    cout << avg << "the avg is " << endl;  //testing the length

    viewer.data(0).add_edges(V + PD*avg, V - PD*avg, red);
    viewer.launch();
}


void view_v_2normal(_Mesh mesh_in, MatrixXd PD, MatrixXd PD2) {
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
    menu.callback_draw_viewer_menu = [&]()
    {
        // Draw parent menu content
        menu.draw_viewer_menu();

        // Add new group
        if (ImGui::CollapsingHeader("New Group", ImGuiTreeNodeFlags_DefaultOpen))
        {
            // Expose variable directly ...
            ImGui::InputDouble("double", &doubleVariable, 0, 0, "%.4f");

            // ... or using a custom callback
            static bool boolVariable = true;
            if (ImGui::Checkbox("bool", &boolVariable))
            {
                // do something
                cout << "boolVariable: " << boolalpha << boolVariable << endl;
            }

            // Expose an enumeration type
            enum Orientation { Up=0, Down, Left, Right };
            static Orientation dir = Up;
            ImGui::Combo("Direction", (int *)(&dir), "Up\0Down\0Left\0Right\0\0");

            // We can also use a vector<string> defined dynamically
            static int num_choices = 3;
            static vector<string> choices;
            static int idx_choice = 0;
            if (ImGui::InputInt("Num letters", &num_choices))
            {
                num_choices = max(1, min(26, num_choices));
            }
            if (num_choices != (int) choices.size())
            {
                choices.resize(num_choices);
                for (int i = 0; i < num_choices; ++i)
                    choices[i] = string(1, 'A' + i);
                if (idx_choice >= num_choices)
                    idx_choice = num_choices - 1;
            }
            ImGui::Combo("Letter", &idx_choice, choices);

            // Add a button
            if (ImGui::Button("Print Hello", ImVec2(-1,0)))
            {
                cout << "Hello\n";
            }
        }
    };

    viewer.data(0).set_mesh(V, F);

//    MatrixXd C;
//    igl::jet(K,true,C);   // K is the input vector to indicate color.
//    viewer.data(0).set_colors(C);

    // for showing the direction of normals.
    const RowVector3d red(0.8,0.2,0.2);
    const RowVector3d blue(0, 1, 0);
    // Average edge length for sizing
    const double avg = igl::avg_edge_length(V,F);
    cout << avg << "the avg is " << endl;  //testing the length

    viewer.data(0).add_edges(V + PD*avg, V - PD*avg, red);
    viewer.data(0).add_edges(V + PD2*avg, V - PD2*avg, blue);
    viewer.launch();
}

int main() {
    std::cout << "Implementation of quad mesh curvature estimation via optimization" << std::endl;
    _Mesh mesh;
    if (!OpenMesh::IO::read_mesh(mesh, "/home/qiang/Documents/codefiles/geo/model/BL2.obj"))
    {
        std::cerr << "read error\n";
        exit(1);
    }
    vv3d_t one_ring_edges;
    vector<size_t> valence;
    v3d_t center;

    MatrixXd v_normals;
    v_normals.resize(mesh.n_vertices(), 3);

    for (auto v_it = mesh.vertices_begin(); v_it != mesh.vertices_end(); v_it++) { // vertex
        center = mesh.point(*v_it);
        for (_Mesh::VertexVertexIter vv_it=mesh.vv_iter( *v_it ); vv_it.is_valid(); ++vv_it){
            auto curr = mesh.point(*vv_it);
            one_ring_edges.push_back(v3d_t(curr-center).normalized());
        }
        valence.push_back(one_ring_edges.size());
        one_ring_edges.push_back(one_ring_edges[0]);

        v3d_t normal = v3d_t(0);
        for(size_t ii = 0; ii < one_ring_edges.size() - 1; ii++) {
            normal += one_ring_edges[ii] % one_ring_edges[ii + 1]; // % is the cross product
        }
        normal /= one_ring_edges.size() - 1;
        one_ring_edges.clear();
        v_normals(v_it->idx(), 0) = normal[0];
        v_normals(v_it->idx(), 1) = normal[1];
        v_normals(v_it->idx(), 2) = normal[2];
    }
//

    // Now we have all the vertex normals
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

//  Now we have all the vertex normals, and face normals
    MatrixXd adj_f_normals;
    MatrixXi edg_orders;
    adj_f_normals.resize(mesh.n_faces(), 12);
    edg_orders.resize(mesh.n_faces(), 4);
    for (auto f_it = mesh.faces_begin(); f_it != mesh.faces_end(); f_it++) { // face
        int face_count = 0;
        for (auto fh_it = mesh.fh_iter(*f_it); fh_it.is_valid(); ++fh_it) {
            edg_orders(f_it->idx(), face_count) = fh_it->idx();
            auto opposite_idx = (mesh.opposite_face_handle(*fh_it)).idx();
            if (!mesh.is_boundary(*fh_it) and opposite_idx!=-1) {
                adj_f_normals(f_it->idx(), 3*face_count) = f_normals.row(opposite_idx)(0);
                adj_f_normals(f_it->idx(), 3*face_count+1) = f_normals.row(opposite_idx)(1);
                adj_f_normals(f_it->idx(), 3*face_count+2) = f_normals.row(opposite_idx)(2);
                face_count++;
            }
        }
    }

    cout<< "f_normals" <<endl<< f_normals<<endl;
    cout<< "v_normals" <<endl<< v_normals<<endl;
    cout<< "adj_f_normals"<<endl << adj_f_normals<<endl;
    cout<< "edg_orders" <<endl<< edg_orders<<endl;
    MatrixXd init_v_normals = v_normals;

    deque<Vector3d> vertices_;
    deque<v3d_t> adj_normals;
    MatrixXd lin_sys_a = MatrixXd::Zero(12, 12);
    VectorXd lin_sys_b; lin_sys_b.resize(12, 1);
    lin_sys_b << 2.0 ,  2.0 ,  2.0 ,  0 ,  2.0 ,  2.0 ,  2.0 ,  2.0, 0.0, 0.0, 0.0, 0.0;
    MatrixXd solution;
    Vector3d f_normal; Vector3d of_normal; //opposite_face_normal
    MatrixXd v_normals_diff = MatrixXd::Zero(4, 3);
    MatrixXd v_normals_diff2 = MatrixXd::Zero(4, 3);
    MatrixXd opp_normals = MatrixXd::Zero(4, 3);
    int f_it_idx;
    vector<size_t> v_idx_of_face; //todo: how to indicate
    vector<double> to_flip;

    set <int, greater<int>> neighbours;
    set <int, greater<int>> vtx_neighbours;
    for (int k =0; k < 200; k++) {
        for (auto f_it = mesh.faces_begin(); f_it != mesh.faces_end(); f_it++) { // face
            f_it_idx = f_it->idx();
            cout << "=====> curr_face " << f_it_idx << "/" << mesh.n_faces() << endl;
            for (size_t ii = 0; ii < 4; ii++) {
                int e = edg_orders(f_it_idx, ii);
                auto edge = mesh.halfedge_handle(e);
                auto v_from = mesh.from_vertex_handle(edge);
                auto f_idx = mesh.face_handle(edge);

                f_normal = f_normals.row(f_idx.idx());
                of_normal(0) = adj_f_normals.row(f_it_idx)(ii * 3);
                of_normal(1) = adj_f_normals.row(f_it_idx)(ii * 3 + 1);
                of_normal(2) = adj_f_normals.row(f_it_idx)(ii * 3 + 2);

                v_idx_of_face.push_back(v_from.idx());
                auto vtx = mesh.point(v_from);
                vertices_.push_back(Vector3d(vtx[0], vtx[1], vtx[2]));
                adj_normals.push_back(v3d_t(of_normal(0), of_normal(1), of_normal(2)));

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
//                        in_vtx_idx = mesh.to_vertex_handle(edge).idx(); // todo: wrong. from
                        in_vtx_idx = v_from.idx(); // todo: wrong. from
                        v_normals_diff(ii, 0) = v_normals(opp_vtx_idx, 0) - v_normals(in_vtx_idx, 0);
                        v_normals_diff(ii, 1) = v_normals(opp_vtx_idx, 1) - v_normals(in_vtx_idx, 1);
                        v_normals_diff(ii, 2) = v_normals(opp_vtx_idx, 2) - v_normals(in_vtx_idx, 2);
                    }
                }

                // find the second pair.
                neighbours.clear();
                if (ii == 0) {e = edg_orders(f_it_idx, 3);}
                else {e = edg_orders(f_it_idx, ii-1);}
                edge = mesh.halfedge_handle(e); opposite_fidx = mesh.opposite_face_handle(edge);
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
                        in_vtx_idx = v_from.idx();
                        v_normals_diff2(ii, 0) = v_normals(opp_vtx_idx, 0) - v_normals(in_vtx_idx, 0);
                        v_normals_diff2(ii, 1) = v_normals(opp_vtx_idx, 1) - v_normals(in_vtx_idx, 1);
                        v_normals_diff2(ii, 2) = v_normals(opp_vtx_idx, 2) - v_normals(in_vtx_idx, 2);
                    }
                }
            }
            // Black-rectangle constraints
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

            // Shape operator constraint
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

            // Adjacent face constraints
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

//            // Adjacent face constraints
//            lin_sys_a(4, 0) = adj_normals[0][0];
//            lin_sys_a(4, 1) = adj_normals[0][1];
//            lin_sys_a(4, 2) = adj_normals[0][2];
//            lin_sys_a(4, 3) = adj_normals[0][0];
//            lin_sys_a(4, 4) = adj_normals[0][1];
//            lin_sys_a(4, 5) = adj_normals[0][2];
//
//            lin_sys_a(5, 3) = adj_normals[1][0];
//            lin_sys_a(5, 4) = adj_normals[1][1];
//            lin_sys_a(5, 5) = adj_normals[1][2];
//            lin_sys_a(5, 6) = adj_normals[1][0];
//            lin_sys_a(5, 7) = adj_normals[1][1];
//            lin_sys_a(5, 8) = adj_normals[1][2];
//
//            lin_sys_a(6, 6) = adj_normals[2][0];
//            lin_sys_a(6, 7) = adj_normals[2][1];
//            lin_sys_a(6, 8) = adj_normals[2][2];
//            lin_sys_a(6, 9) = adj_normals[2][0];
//            lin_sys_a(6, 10) = adj_normals[2][1];
//            lin_sys_a(6, 11) = adj_normals[2][2];
//
//            lin_sys_a(7, 0) = adj_normals[3][0];
//            lin_sys_a(7, 1) = adj_normals[3][1];
//            lin_sys_a(7, 2) = adj_normals[3][2];
//            lin_sys_a(7, 9) = adj_normals[3][0];
//            lin_sys_a(7, 10) = adj_normals[3][1];
//            lin_sys_a(7, 11) = adj_normals[3][2];
//            // gordon's: inline constraint
//            lin_sys_a(8, 0) = v_normals_diff(0, 0);
//            lin_sys_a(8, 1) = v_normals_diff(0, 1);
//            lin_sys_a(8, 2) = v_normals_diff(0, 2);
//
//            lin_sys_a(9, 3) = v_normals_diff(1, 0);
//            lin_sys_a(9, 4) = v_normals_diff(1, 1);
//            lin_sys_a(9, 5) = v_normals_diff(1, 2);
//
//            lin_sys_a(10, 6) = v_normals_diff(2, 0);
//            lin_sys_a(10, 7) = v_normals_diff(2, 1);
//            lin_sys_a(10, 8) = v_normals_diff(2, 2);
//
//            lin_sys_a(11, 9) = v_normals_diff(3, 0);
//            lin_sys_a(11, 10) = v_normals_diff(3, 1);
//            lin_sys_a(11, 11) = v_normals_diff(3, 2);

            solution = lin_sys_a.colPivHouseholderQr().solve(lin_sys_b);
            v_normals(v_idx_of_face[0], 0) = solution(0);
            v_normals(v_idx_of_face[0], 1) = solution(1);
            v_normals(v_idx_of_face[0], 2) = solution(2);
            v_normals(v_idx_of_face[1], 0) = solution(3);
            v_normals(v_idx_of_face[1], 1) = solution(4);
            v_normals(v_idx_of_face[1], 2) = solution(5);
            v_normals(v_idx_of_face[2], 0) = solution(6);
            v_normals(v_idx_of_face[2], 1) = solution(7);
            v_normals(v_idx_of_face[2], 2) = solution(8);
            v_normals(v_idx_of_face[3], 0) = solution(9);
            v_normals(v_idx_of_face[3], 1) = solution(10);
            v_normals(v_idx_of_face[3], 2) = solution(11);

            cout << "\t\tRelative error " << (lin_sys_a * solution - lin_sys_b).norm() / lin_sys_b.norm() << endl;
            v_idx_of_face.clear();
            adj_normals.clear();
            lin_sys_a = MatrixXd::Zero(12, 12);
            neighbours.clear(); vtx_neighbours.clear();
            v_normals_diff = MatrixXd::Zero(4, 3);
        }
    }

    view_f_normals(mesh, f_normals, f_centers);
    view_v_2normal(mesh, init_v_normals, v_normals);
    return 0;
}
