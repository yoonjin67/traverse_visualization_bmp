#pragma pack(2)
typedef unsigned int dword;
typedef unsigned char byte;
typedef unsigned short word;
constexpr float inch = 39.3701;
constexpr dword info_header_size = 40;
constexpr int file_header_size = 14;
constexpr int filetype_bmp = 0x4d42;
constexpr word img_depth = 24;
class bitmap_file_header {
    public:
    word bf_type;
    dword bf_size;
    word bf_reserved_1;
    word bf_reserved_2;
    dword bf_off_bits;
    void initialize();
};

class bitmap_info_header {
    public:
    dword bi_size;
    long bi_width;
    long bi_height;
    word bi_planes;
    word bi_count;
    dword bi_compression;
    dword bi_size_image;
    long bi_xpels_per_meter;
    long bi_ypels_per_meter;
    dword bi_clr_used;
    dword bi_clr_important;
    void initialize();
    void set_abstract_dpi(unsigned dpi);
};

class rgb_quad {
    public:
    byte blue;
    byte green;
    byte red;
    void color(long x);
    int get_color();
};