#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include <CGAL/Regular_triangulation_euclidean_traits_3.h>
#include <CGAL/Periodic_3_regular_triangulation_traits_3.h>
#include <CGAL/Periodic_3_regular_triangulation_3.h>

#include <iostream>


typedef CGAL::Epick K;
typedef K::FT FT;

typedef CGAL::Regular_triangulation_euclidean_traits_3<K>   RT;
typedef CGAL::Periodic_3_regular_triangulation_traits_3<RT> Traits;
typedef CGAL::Periodic_3_regular_triangulation_3<Traits>    P3RT3;

typedef Traits::Iso_cuboid_3 Iso_cuboid;

typedef P3RT3::Vertex_handle Vertex_handle;
typedef P3RT3::Weighted_point Weighted_point;
typedef P3RT3::Bare_point Bare_point;


int main ()
{
  P3RT3 p3rt3(P3RT3::Iso_cuboid(0,0,0, 1,1,1));

  p3rt3.insert(Weighted_point(Bare_point(0.1,0.1,0.1),0.01));
  p3rt3.insert(Weighted_point(Bare_point(0.9,0.1,0.1),0.01));
  p3rt3.insert(Weighted_point(Bare_point(0.1,0.9,0.1),0.01));
  p3rt3.insert(Weighted_point(Bare_point(0.1,0.1,0.9),0.01));
  p3rt3.insert(Weighted_point(Bare_point(0.4, 0.4, 0.4), 0.001));

  while (p3rt3.number_of_vertices())
    p3rt3.remove(p3rt3.vertices_begin());

  std::cout << "EXIT SUCCESS" << std::endl;
  return 0;
}
