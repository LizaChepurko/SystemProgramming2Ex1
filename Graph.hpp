/**
 * ID 211548268
 * Mail: lizachep@gmail.com
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
using namespace std;
namespace ariel
{
    class Graph
    {
        public:
            vector<vector<int>> _graph;
            void loadGraph(vector<vector<int>> graph);

            void printGraph() const;

            int size() const;

        private:
            void validateGraph() const ;
            
    }; // class Graph

}; // namespace ariel

#endif