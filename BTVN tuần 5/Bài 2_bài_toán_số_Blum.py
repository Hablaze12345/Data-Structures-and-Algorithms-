import math
#Hàm kiểm tra số nguyên tố có dạng 4k3
def is_4k3_prime(n):
    return n % 4==3
#Sàng Eratosthenes để tìm các số nguyên tố nhỏ hơn n
def sieve_eratosthenes(limit):
    #Bước 1 : Khởi tạo mảng boolean để đánh dấu số nào là số nguyên tố
    sieve= [True]*(limit+1) #Tất cả ban đầu là True
    sieve[0]=sieve[1]= False #Đặt 0 và 1 là False vì không phải số nguyên tố
    for i in range(2, int (math.sqrt(limit))+1): #Duyệt từ 2 đến sqrt(limit)+1
        if sieve[i] : #Nếu i là số nguyên tố
            for j in range(i*i,limit +1,i): #Đánh dấu tất cả bội số của i là False, bắt đầu từ i*i
                sieve[j]=False
    #Bước 3 : Lọc ra các số nguyên tố dạng 4k+3
    return [x for x in range(limit + 1) if sieve[x] and is_4k3_prime(x)]

#Tạo danh sách số Blum nhỏ hơn N
def generate_Blum_numbers(N):
    primes=sieve_eratosthenes(int(math.sqrt(N))+1)
    blum_numbers=set()
    for i in range(len(primes)):
        for j in range(i+1,len(primes)):
            blum_number=primes[i]*primes[j]
            if blum_number<N :
                blum_numbers.add(blum_number)
    return sorted(blum_numbers)
#Kiểm tra 1 số có phải số Blum không
def is_blum_number(n, blum_numbers):
    return n in blum_numbers

#Tìm tất cả các cặp số Blum có tổng cũng là số Blum
def find_blum_pairs(blum_numbers,N):
    blum_pairs=[]
    blum_set=set(blum_numbers)
    for i in range(len(blum_numbers)):
        for j in range(i,len(blum_numbers)):
            if blum_numbers[i] + blum_numbers[j] < N and (blum_numbers[i] + blum_numbers[j]) in blum_set:
                blum_pairs.append((blum_numbers[i], blum_numbers[j]))
    return blum_pairs


# Hàm chính
def main(N, M):
    # Tạo danh sách số Blum
    blum_numbers = generate_Blum_numbers(N)
    print(f"Các số Blum nhỏ hơn {N}: {blum_numbers}")

    # Yêu cầu 1: Tìm các cặp số Blum có tổng là số Blum
    blum_pairs = find_blum_pairs(blum_numbers, N)
    print(f"Các cặp số Blum có tổng cũng là số Blum nhỏ hơn {N}: {blum_pairs}")

    # Yêu cầu 2: Kiểm tra số Blum M có trong danh sách không
    if is_blum_number(M, blum_numbers):
        print(f"Số Blum {M} có tồn tại trong dãy số Blum được tạo ra.")
    else:
        print(f"Số Blum {M} không tồn tại trong dãy số Blum được tạo ra.")

N=2000
M=21
main(N,M)

