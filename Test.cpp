/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 * I added tests
 */

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


using namespace std;


TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected with disconnected graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}}; // 2 is isolated
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph2 = {
    {0, 0, 0, 0},  // 0 is isolated
    {0, 1, 0, 0},  // 1 connects to 2
    {0, 0, 1, 1},  // 2 connects to 3
    {0, 0, 1, 0}   // 3 connects to 2
  };
  g.loadGraph(graph2);

  CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == true);

    
    vector<vector<int>> graph1 = {
    {0, 1, 0, 1},  
    {1, 0, 1, 0},  
    {0, 1, 0, 1},  
    {1, 0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == true);
    
    
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == true);

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 1) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 2, 2) == true);
}

TEST_CASE("Test shortestPath with disconnected nodes")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},  // 0 connects to 1
        {1, 0, 0},  // 1 connects to 0
        {0, 0, 0}}; // 2 is isolated
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == false);

    
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},  // 0 connects to 1 2
        {1, 0, 1, 0, 0},  // 1 connects to 0 2 
        {1, 1, 0, 1, 0},  // 2 connects to 0 1 3
        {0, 0, 1, 0, 0},  // 3 connects to 2
        {0, 0, 0, 0, 0}}; // 4 is isolated
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == false);
}

TEST_CASE("Test shortestPath with invalid source or destination")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, -1, 0) == false);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, -1) == false);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 3) == false);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 3, 0) == false);
}


TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isContainsCycle with acyclic graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isContainsCycle with negative cycle in the graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {2, 0, 0, 0},
        {0, 0,-5, 0},
        {6, 0, 0, 4},
        {0,-3, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}



TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == false);

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == true);

  
    vector<vector<int>> graph5 = {
    {0, 1, 0, 0},  
    {1, 0, 1, 0}, 
    {0, 1, 0, 1},  
    {0, 0, 1, 0}   
  };
  g.loadGraph(graph5);

  CHECK(ariel::Algorithms::isBipartite(g) == true);
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test empty graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {};
    g.loadGraph(graph);
    CHECK_THROWS(ariel::Algorithms::isConnected(g));
    CHECK_THROWS(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK_THROWS(ariel::Algorithms::isBipartite(g) == false);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 1) == false);
}