# 직접 실행하며 알아보는 BFS와 DFS의 차이점

## Datatypes

![Datatypes HPP](./datatypes.hpp)
![Datatypes CPP](./datatypes.cpp)

데이터 타입이 정의되어 있는 부분입니다.
클래스 등을 잘 확인하세요.
만약 구조체가 더욱 정밀하게 정의되어 보다 밀도있는 비트맵 헤더 정보를 정의하게 하려면 이 부분을 수정해야 할 것입니다.
또한, Color Value를 계산하는 Bit Shift 역시 여기에 정의되어 있습니다.
필요하다면 이 알고리즘을 수정하여 보다 깔끔한 심도 시각화를 하여도 됩니다.

## Bitmap Namespace

![Bitmap Namespace HPP](./bmp_ns.hpp)
![Bitmap Namespace CPP](./bmp_ns.cpp)

비트맵 네임스페이스의 안에 BFS, DFS 메서드가 포함되어 있습니다.
이는 main.cpp를 간소화하고 코드 자체의 목적이 탐색과 Bitmap을 따로 구현하는 것이 아니기 때문입니다.
탐색에 필요한 함수들과 이미지 작업에 대해 정의되어 있습니다.

## Main

이제, main.cpp 부분을 보도록 하겠습니다.

```c
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
```

비트맵 이미지의 체계 때문에, 0,0이 아닌 끝 행의 0 지점부터 탐색해야 좌상단->우하단으로 탐색이 자연스럽게 진행됩니다.
또한, 앞서 사용한 방식대로 탐색과 이미지 작업이 한 데서 이루어지게 되며 메인 함수가 아주 효율적으로 축소되었습니다. 이는 기능 지향적인 설계가 항상 효율적이고 통합된 코드를 설계하지만은 않는다는 것을 보여주는 방증이 됩니다.


### Posts

탐색에 대해 보다 자세하게 설명한, 알고리즘 중심으로 설명하는 게시물을 보고 싶다면 아래를 참고하세요.

![BFS와-DFS-시각화.html](https://yoonjin67.github.io/blog/2025/05/09/BFS%EC%99%80-DFS-%EC%8B%9C%EA%B0%81%ED%99%94.html)
