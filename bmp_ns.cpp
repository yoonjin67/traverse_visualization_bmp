#include "bmp_ns.hpp"
#include<cstdio>
#include<queue>
constexpr int CNT=1;
namespace bitmap {
    bitmap_file_header file_header;
    bitmap_info_header info_header;
    vector<vector<rgb_quad>> image_data;
    vector<vector<bool>> visited;
    void setup_size( int row, int col) {
        rgb_quad r;
        r.blue = 0;
        r.red = 0;
        r.green = 0;
        file_header.initialize();
        info_header.initialize();
        info_header.set_abstract_dpi(72);
        image_data = vector<vector<rgb_quad>>(row,vector<rgb_quad>(col, r));
        visited = vector<vector<bool>>(row,vector<bool>(col,false));
        info_header.bi_width = col;
        info_header.bi_height = row;
        info_header.bi_size_image = col * row;
        file_header.bf_size = info_header.bi_size_image + info_header_size+file_header_size;
    }
    bool is_avail(int row, int col) {
        if((row>=image_data.size()) || (row<0)) {
            return false;
        }
        if(col>=image_data[0].size() || (col<0)) {
            return false;
        }
        return !visited[row][col];
    }
    void dfs(int row, int col, int depth) {
        if(!is_avail(row,col)) return;
        visited[row][col] = true;
        image_data[row][col].color(depth);
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};
        for(int i = 0; i < 4; i++) {
            int nrow = row+drow[i], ncol = col+dcol[i];
            if(is_avail(nrow,ncol)) {
                dfs(nrow,ncol,depth+CNT);
            }
        }
    }
    void bfs(int row, int col) {
        std::queue<pair<int,int>> q;
        q.push(make_pair(row,col));
        image_data[row][col].color(0);
        while(q.size()) {
            pair<int,int> point = q.front();
            int cur_row = point.first, cur_col = point.second;
            visited[cur_row][cur_col] = true;
            int cur_color = image_data[cur_row][cur_col].get_color();
            q.pop();
            int drow[] = {-1,1,0,0};
            int dcol[] = {0,0,-1,1};
            for(int i = 0; i < 4; i++) {
                int nrow = drow[i]+cur_row, ncol = dcol[i]+cur_col;
                if(is_avail(nrow,ncol)) {
                    visited[nrow][ncol] = true;
                    q.push(make_pair(nrow,ncol));
                    image_data[nrow][ncol].color(cur_color+CNT);
                }
            }
        }
    }
    void write_image(char *filename) {
        FILE *f = fopen(filename,"wb");
        fwrite(&file_header,sizeof(file_header),1,f);
        fwrite(&info_header,sizeof(info_header),1,f);
        for(auto row:image_data) {
            for(auto col:row) {
                fwrite(&col,sizeof(rgb_quad),1,f);
            }
        }
        fclose(f);
    }
}
