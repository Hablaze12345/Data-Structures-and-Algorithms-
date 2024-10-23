def nhap():
    n = int(input("Nhập số phần tử của mảng a: "))
    a = []
    for i in range(n):
        a.append(int(input(f"Nhập phần tử thứ {i + 1} của mảng a: ")))
    m = int(input("Nhập số phần tử của mảng b: "))
    b = []
    for i in range(m):
        b.append(int(input(f"Nhập phần tử thứ {i + 1} của mảng b: ")))
    return a, b, n, m


def xuat(a, n):
    print("Mảng:", a)


def tron(a, b):
    c = []
    i = j = 0
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    c.extend(a[i:])
    c.extend(b[j:])
    return c


def xuat_tron(c, m):
    print("c:", c)


# Sử dụng chương trình
a, b, n, m = nhap()
xuat(a, n)
xuat(b, m)
c = tron(a, b)
c.sort()  # Sắp xếp mảng c sau khi trộn
xuat_tron(c, len(c))