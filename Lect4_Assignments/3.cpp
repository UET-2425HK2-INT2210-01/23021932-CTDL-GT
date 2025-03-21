/*

Công thức: h(i) = (i + 3) mod 17

    Khóa              	Vị trí
    1	                (1 + 3) mod 17 = 4
    3	                (3 + 3) mod 17 = 6
    18	                (18 + 3) mod 17 = 4 (va chạm)
    8	                (8 + 3) mod 17 = 11
    23	                (23 + 3) mod 17 = 9
    35	                (35 + 3) mod 17 = 4 (va chạm)
    11	                (11 + 3) mod 17 = 14
    36	                (36 + 3) mod 17 = 5
    20	                (20 + 3) mod 17 = 6 (va chạm)
    16	                (16 + 3) mod 17 = 2

a. Xử lý va chạm bằng chaining (danh sách liên kết)

    0: NULL
    1: NULL
    2: 16 -> NULL
    3: NULL
    4: 1 -> 18 -> 35 -> NULL
    5: 36 -> NULL
    6: 3 -> 20 -> NULL
    7: NULL
    8: NULL
    9: 23 -> NULL
    10: NULL
    11: 8 -> NULL
    12: NULL
    13: NULL
    14: 11 -> NULL
    15: NULL
    16: NULL

b. Xử lý va chạm bằng linear probing (tuyến tính)
    0: NULL
    1: NULL
    2: 16
    3: NULL
    4: 1
    5: 18
    6: 3
    7: 35
    8: 36
    9: 23
    10: 20
    11: 8
    12: NULL
    13: NULL
    14: 11
    15: NULL
    16: NULL

*/