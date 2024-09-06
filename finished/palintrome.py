num = int(input("Enter number for Palintrome test : "))
original = num
rev = 0

while int(num) != 0:
    rev = rev*10 + int(num)%10
    num = num / 10
if rev == original:
    print(original,"Is a Palintrome")
else:
    print(original,"Is NOT a Palintrome")