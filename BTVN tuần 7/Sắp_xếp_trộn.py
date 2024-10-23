def nhap():
    n = int(input("Nhập số phần tử của mảng: "))
    a = []
    for i in range(n):
        a.append(int(input(f"Nhập phần tử thứ {i + 1}: ")))
    return a, n

def xuat(a, n):
    print("Mảng ban đầu:", a)

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
    print("Mảng sau khi trộn:", c)

def merge_sort(a):
    if len(a) <= 1:
        return a
    mid = len(a) // 2
    left = merge_sort(a[:mid])
    right = merge_sort(a[mid:])
    return tron(left, right)

# Sử dụng chương trình
a, n = nhap()
xuat(a, n)
a = merge_sort(a)
xuat_tron(a, len(a))