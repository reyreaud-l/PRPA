#include <iostream>
#include "greedy/greedy.hh"
#include "loader/loader.hh"
#include "graph/graph.hh"

int main(int argc, char **argv)
{
   if (argc < 2)
   {
      std::cout << "Usage: [t] [input_file]\n With input file being"
                << "a csv file name,x,y";
      return 1;
   }

   auto mygraph = Loader::Load(argv[1]);
/*  auto mygraph = Graph<>();
  for(int i = 0; i < 10; i++)
  {
    auto vertice = boost::add_vertex(mygraph);
    auto& data = mygraph[vertice];
    data.x = i;
    data.y = i;
  }
*/

  auto it = boost::vertices(mygraph);
  for (;it.first != it.second; it.first++)
  {
    auto vertice = *it.first;
    auto data = mygraph[vertice];
    std::cout << "Node: x -> " << data.x
      << "\n      y -> " << data.y << std::endl;
  }
  return 0;
}
