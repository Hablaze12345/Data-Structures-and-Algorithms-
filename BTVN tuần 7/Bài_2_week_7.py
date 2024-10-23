# Mảng lưu các năm và số lượng người sinh ra tương ứng
years = [1920, 1921, 1922, 1923, 1924, 1925, 1926, 1927, 1928, 1929,
         1930, 1931, 1932, 1933, 1934, 1935, 1936, 1937, 1938, 1939,
         1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947, 1948, 1949,
         1950, 1951, 1952, 1953, 1954, 1955, 1956, 1957, 1958, 1959,
         1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, 1968, 1969, 1970]

birth_counts = [19, 77, 40, 90, 2, 25, 54, 17, 79, 6,
                44, 24, 14, 4, 95, 47, 66, 48, 23, 98,
                15, 86, 25, 50, 9, 29, 64, 3, 67, 4,
                90, 81, 74, 34, 98, 13, 87, 96, 56, 90,
                49, 85, 94, 66, 19, 95, 47, 42, 65, 87, 11]

# 1. In ra những năm không có người nào sinh ra
print("Những năm không có người nào sinh ra:")
for i in range(len(years)):
    if birth_counts[i] == 0:
        print(years[i])

# 2. Tính số lượng những năm có số người sinh ra không quá 10
years_with_birth_10 = 0
for i in range(len(birth_counts)):
    if birth_counts[i] <10:
        years_with_birth_10 += 1
print(f"Số lượng những năm có số người sinh ra không quá 10: {years_with_birth_10}")

# 3. Tính số người đã trên 50 tuổi tính đến năm 1985
people_over_50_in_1985 = 0
for i in range(len(years)):
    if years[i] <= 1935:
        people_over_50_in_1985 += birth_counts[i]
print(f"Số người đã trên 50 tuổi tính đến năm 1985: {people_over_50_in_1985}")

# 4. Tìm số năm có cùng số lượng người sinh ra
birth_count_frequency = {}

# Đếm tần suất xuất hiện của mỗi số lượng người sinh ra
for i in range(len(birth_counts)):
    count = birth_counts[i]
    if count in birth_count_frequency:
        birth_count_frequency[count] += 1
    else:
        birth_count_frequency[count] = 1

print("Số năm có cùng số lượng người sinh ra :")
for count in birth_count_frequency:
    if birth_count_frequency[count] > 1:
        print(f"{birth_count_frequency[count]} năm có {count} người sinh ra")

# 5. In ra các năm có số lượng người sinh ra lớn nhất và nhỏ nhất
max_birth = birth_counts[0]
min_birth = birth_counts[0]

# Tìm giá trị lớn nhất và nhỏ nhất
for i in range(1, len(birth_counts)):
    if birth_counts[i] > max_birth:
        max_birth = birth_counts[i]
    if birth_counts[i] < min_birth:
        min_birth = birth_counts[i]

# Tìm các năm tương ứng với giá trị lớn nhất và nhỏ nhất
years_with_max_birth = []
years_with_min_birth = []

for i in range(len(birth_counts)):
    if birth_counts[i] == max_birth:
        years_with_max_birth.append(years[i])
    if birth_counts[i] == min_birth:
        years_with_min_birth.append(years[i])

print(f"Các năm có số người sinh ra lớn nhất ({max_birth}): {years_with_max_birth}")
print(f"Các năm có số người sinh ra nhỏ nhất ({min_birth}): {years_with_min_birth}")