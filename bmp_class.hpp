#pragma pack(2)
#include "datatypes.hpp"
#include<vector>
using namespace std;
namespace bitmap {
    extern bitmap_file_header file_header;
    extern bitmap_info_header info_header;
    extern vector<vector<rgb_quad>> image_data;
    extern vector<vector<bool>> visited;
    void setup_size(int row, int col);
    void bfs(int row, int col);
    void dfs(int row, int col, int depth);
    bool is_avail(int row, int col);
    void write_image(char * filename);
}