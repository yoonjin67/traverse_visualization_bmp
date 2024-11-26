#include "datatypes.hpp"
#include<cstring>

void bitmap_info_header::initialize() {
    memset(this,0,sizeof(*this));
    this->bi_planes = 1;
    this->bi_count = img_depth;
    this->bi_size = info_header_size;
}
void bitmap_file_header::initialize() {
    memset(this,0,sizeof(*this));
    bf_type = filetype_bmp;
    bf_off_bits = file_header_size + info_header_size;
    bf_reserved_1 = 0;
    bf_reserved_2 = 0;
}

void rgb_quad::color(long x) {
    this->blue=static_cast<byte>(x);
    this->green=static_cast<byte>(x>>8);
    this->red=static_cast<byte>(x>>16);
}
int rgb_quad::get_color() {
    int ret = 0;
    ret |= this->blue;
    ret |= this->green<<8;
    ret |= this->red<<16;
    return ret;
}
void bitmap_info_header::set_abstract_dpi(unsigned dpi) {
    this->bi_xpels_per_meter = this->bi_ypels_per_meter = dpi*inch;
}