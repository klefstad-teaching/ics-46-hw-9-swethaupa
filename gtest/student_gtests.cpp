#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Ladder, EditDistanceWithin) {
  EXPECT_TRUE(edit_distance_within("cat", "cat", 0));
  EXPECT_TRUE(edit_distance_within("cat", "hat", 1));
  EXPECT_FALSE(edit_distance_within("cat", "dog", 1));
}

TEST(Ladder, IsAdjacent) {
  EXPECT_TRUE(is_adjacent("cat", "sat"));
  EXPECT_FALSE(is_adjacent("cat", "dog"));
}

TEST(Ladder, WordLadder) {
  set<string> words = {"dog", "fog", "fig", "pig"};
  EXPECT_TRUE(generate_word_ladder("dog", "pig", words).size() == 4);
}

TEST(Dijkstras, ShortestPath) {
  Graph G;
  G.numVertices = 3;
  G.resize(3);
  
  G[0].push_back(Edge(0, 1, 5));
  G[0].push_back(Edge(0, 2, 10));
  G[1].push_back(Edge(1, 2, 3));
  
  vector<int> previous;
  vector<int> distances = dijkstra_shortest_path(G, 0, previous);
  
  EXPECT_TRUE(distances[0] == 0);
  EXPECT_TRUE(distances[1] == 5);
  
  EXPECT_TRUE(previous[0] == -1);
  EXPECT_TRUE(previous[1] == 0);
}

TEST(Dijkstras, ExtractShortestPath) {
  vector<int> distances = {0, 5, 8};
  vector<int> previous = {-1, 0, 1};
  
  vector<int> path_to_2 = extract_shortest_path(distances, previous, 2);
  EXPECT_TRUE(path_to_2.size() == 3);
  EXPECT_TRUE(path_to_2[0] == 0);
  EXPECT_TRUE(path_to_2[1] == 1);
  EXPECT_TRUE(path_to_2[2] == 2);
}
