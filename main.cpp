#include "bmp_ns.hpp"
using namespace std;
using namespace bitmap;
int main() {
    int row = 120, col = 120;
    setup_size(row,col);
    bfs(row-1,0);
    write_image("bfs.bmp");
    setup_size(row,col);
    dfs(row-1,0,0);
    write_image("dfs.bmp");
    return 0;
}
