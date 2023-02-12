#include <vector>
#include <string>

const int NUM_SQUARES = 9;
const int NUM_CORNERS = 4;
const int NUM_MIDDLES = 4;
const int CENTER = 4;

std::vector<int> available_moves = {0, 1, 2, 3, 4, 5, 6, 7, 8};
std::string who_started = "";
std::vector<std::string> board(NUM_SQUARES, " ");
std::vector<int> corners = {0, 2, 6, 8};
std::vector<int> middles = {1, 3, 5, 7};