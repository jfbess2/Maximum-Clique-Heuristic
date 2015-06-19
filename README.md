# Maximum-Clique-Heuristic
Given edges and weights, it can not optimally find the maximum clique in polynomial time.


The clique problem is an NP complete problem. A clique is subset of vertices which create a complete subgraph (all vertices in subgraph have an edge to all other vertices in subgraph).  There are many applications of clique, especially in bioinformatics and ecological systems. The strength and stability of an ecosystem is able to be measured through the maximum clique size.  The focus will be on finding the maximum clique of a given undirected graph.  As of now the fastest algorithm for finding the max clique of an arbitrary graph is 1.1888^n by J. M. Robson.  A heuristic which solves the maximum clique will be presented.  It uses a unique adjacency list which the vertex’s list includes itself in it. This allows finding cliques through checking intersection. 
