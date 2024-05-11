/**
 * ID 211548268
 * Mail: lizachep@gmail.com
*/


#include "Graph.hpp"
#include <iostream>

using namespace std;

namespace ariel
{
        /**
     * @brief Loads a new graph into the object.
     * 
     * This function replaces the current graph with the specified one,
     * performs a validation check to ensure the graph is square,
     * and throws an exception if the graph is invalid.
     * 
     * @param graph The new graph to load.
     * 
     * @throws std::invalid_argument If the input graph is not square.
     */
    void Graph::loadGraph(vector<vector<int>> graph)
    {
            // Clear the graph before loading the new one.
            this->_graph.clear();

            // Copy the new graph.
            for (const auto& row : graph) {
                vector<int> rowCopy(row.begin(), row.end());
                this->_graph.push_back(rowCopy);
            }

            // Validate the graph.
            this->validateGraph();
    }

    /**
     * This function prints the number of vertices and edges in the graph.
     */
    void Graph::printGraph() const
    {
        int vertices = this->_graph.size();
        int edges = 0;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (this->_graph[i][j] != 0)
                {
                    edges++;
                }
            }
        }
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;
    }

    /**
     * Returns the number of vertices.
    */

    int Graph:: size() const
    {
        return this -> _graph.size();
    }

    /**
     * @brief Validates the integrity of the graph.
     * 
     * This function checks if the graph is square.
     * If the graph is not square, it throws an exception.
     * 
     * @throws std::invalid_argument If the graph is not square.
     */

    void Graph::validateGraph() const
    {
        int vertices = this->_graph.size();
        for (int i = 0; i < vertices; i++)
        {
            if (this->_graph[i].size() != vertices)
            {
                cout<<"Invalid graph: The graph is not a square matrix."<<endl;
                throw invalid_argument("Invalid graph.");
            }
        }
    }
}; 