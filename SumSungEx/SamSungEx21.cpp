/* Mã giả
 * Input: Đồ thị có trọng số G, Tập cạnh S không chứa chu trình

1. Khởi tạo G' với tập cạnh S và tập đỉnh V' chứa tất cả các đỉnh thuộc S.
2. Sắp xếp tập cạnh S theo trọng số tăng dần.
3. Khởi tạo một tập rỗng C chứa các cạnh không thuộc S từ G.
4. Khởi tạo các tập con (subsets) cho mỗi đỉnh trong V' bước này chủ yếu dành cho thuật toán disjoint set union.
5. Lặp qua mỗi cạnh e trong S:
     a. Nếu cạnh e không tạo thành chu trình với các cạnh trong C:
          i. Thêm cạnh e vào C.
          ii. Nếu số lượng cạnh trong C bằng V' - 1, thoát khỏi vòng lặp.
6. Lặp qua mỗi cạnh e trong G:
     a. Nếu cạnh e không thuộc S và không tạo thành chu trình với các cạnh trong C:
          i. Thêm cạnh e vào C.
          ii. Nếu số lượng cạnh trong C bằng V' - 1, thoát khỏi vòng lặp.
7. Output: Cây bao trùm C, chứa tất cả các cạnh của S và một số cạnh khác từ G.


 */