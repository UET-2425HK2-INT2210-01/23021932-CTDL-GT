/*

Công thức: h(x) = (2 * x + 5) mod 11

a. Xử lý va chạm bằng chaining (danh sách liên kết)

    h(12)=(2*12+5) mod 11 = 29 mod 11 =  7
    h(44)=(2*44+5) mod 11 = 93 mod 11 =  5
    h(13)=(2*13+5) mod 11 = 31 mod 11 =  9
    h(88)=(2*88+5) mod 11 = 181 mod 11 = 5
    h(23)=(2*23+5) mod 11 = 51 mod 11 =  7
    h(94)=(2*94+5) mod 11 = 193 mod 11 = 6
    h(11)=(2*11+5) mod 11 = 27 mod 11 =  5
    h(39)=(2*39+5) mod 11 = 83 mod 11 =  5
    h(20)=(2*20+5) mod 11 = 45 mod 11 =  1
    h(16)=(2*16+5) mod 11 = 37 mod 11 =  4
    h(5) =(2*5+5)  mod 11 = 15 mod 11 =  4

    0: NULL
    1: 20
    2: NULL
    3: NULL
    4: 16 -> 5 ->NULL
    5: 44 -> 88 ->11 -> NULL
    6: 94 -> 39 -> NULL
    7: 12 -> 23 -> NULL
    8: NULL
    9: 13 -> NULL
    10: NULL

b. Xử lý va chạm bằng linear probing (tuyến tính)
    0: 11
    1: 39
    2: 20
    3: 5
    4: 16
    5: 44
    6: 88
    7: 12
    8: 23
    9: 13
    10: 94

*/