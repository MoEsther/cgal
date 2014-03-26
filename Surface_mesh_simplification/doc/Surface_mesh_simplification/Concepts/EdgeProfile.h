
/*!
\ingroup PkgSurfaceMeshSimplificationConcepts
\cgalConcept

The concept `EdgeProfile` describes the requirements for a data structure that caches the local topology and geometry in the surroundings of an undirected edge. 

This profile is used by the stop, cost and placement policies. 

\cgalHasModel `CGAL::Surface_mesh_simplification::Edge_profile<ECM>`

*/

class EdgeProfile {
public:

/// \name Types 
/// @{

/*!
The type of the surface mesh to simplify. Must be a model of the `EdgeCollapsableSurfaceMesh` concept. 
*/ 
typedef unspecified_type ECM; 

/*!
A <span class="textsc">Bgl</span> vertex descriptor representing a vertex of the surface mesh. 
*/ 
typename boost::graph_traits<ECM>::vertex_descriptor vertex_descriptor; 

/*!
A <span class="textsc">Bgl</span> edge descriptor representing an edge of the surface mesh. 
*/ 
typename boost::graph_traits<ECM>::edge_descriptor edge_descriptor; 

/*!
The point type for the surface mesh vertex. Must be a model of `Point_3`. 
*/ 
typename CGAL::halfedge_graph_traits<ECM>::Point Point; 

/// @} 

/// \name Access Functions 
/// @{

/*!
One of vertices of the edge to be collapsed. 
*/ 
vertex_descriptor v0() const; 

/*!
The other vertex of the edge to be collapsed. 
*/ 
vertex_descriptor v1() const; 

/*!
One of the directed edges corresponding to the undirected 
edge being collapsed. 
*/ 
edge_descriptor v0_v1() const; 

/*!
The other directed edge corresponding to the undirected 
edge being collapsed. 
*/ 
edge_descriptor v1_v0() const; 

/*!
The point of vertex ` v0`. 
*/ 
Point const& p0() const; 

/*!
The point of vertex ` v1`. 
*/ 
Point const& p1() const; 

/*!
If ` v0v1` belongs to a finite face (is not a border edge) 
the third vertex of that triangular face, a <I>null descriptor</I> otherwise. 
*/ 
vertex_descriptor vL() const; 

/*!
If ` v0v1` belongs to a finite face (is not a border edge) 
the directed edge from ` v1` to ` vL`, a <I>null descriptor</I> otherwise. 
*/ 
edge_descriptor v1_vL() const; 

/*!
If ` v0v1` belongs to a finite face (is not a border edge) 
the directed edge from ` vL` to ` v0`, a <I>null descriptor</I> otherwise. 
*/ 
edge_descriptor vL_v0() const; 

/*!
If ` v1v0` belongs to a finite face (is not a border edge) 
the third vertex of that triangular face, a <I>null descriptor</I> otherwise. 
*/ 
vertex_descriptor vR() const; 

/*!
If ` v1v0` belongs to a finite face (is not a border edge) 
the directed edge from ` v0` to ` vR`, a <I>null descriptor</I> otherwise. 
*/ 
edge_descriptor v0_vR() const; 

/*!
If ` v1v0` belongs to a finite face (is not a border edge) 
the directed edge from ` vR` to ` v1`, a <I>null descriptor</I> otherwise. 
*/ 
edge_descriptor vR_v1() const; 

/*!
The unique sequence of the vertices 
around ` v0v1` in topological order (<I>ccw</I> or <I>ccw</I> depending 
on the relative ordering of `v0` and `v1` in the profile). 
*/ 
std::vector<vertex_descriptor> link() const; 

/*!
The unique collection of the border directed edges incident upon ` v0` and ` v1`. 
*/ 
std::vector<edge_descriptor> border_edges() const; 

/*!
Indicates if `v0v1` belongs to a finite face of the surface mesh (i.e, `v0v1` is not a border edge). 
*/ 
bool left_face_exits() const; 

/*!
Indicates if `v0v1` belongs to a finite face of the surface mesh (i.e, `v1v0` is not a border edge). 
*/ 
bool right_face_exits() const; 

/*!
Returns the surface mesh the edge belongs to.
*/
const ECM& surface_mesh() const;

/// @}

}; /* end EdgeProfile */

