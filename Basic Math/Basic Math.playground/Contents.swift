
func numberOfDivisibleDigits(num : Int) -> Int {
    var numStr = String(num)
    var count = 0
    for digit in numStr {
        if digit.wholeNumberValue != 0 && num%digit.wholeNumberValue! == 0 {
            count += 1
        }
    }
    return count
}


print(numberOfDivisibleDigits(num: 10))


func reverse(_ x: Int) -> Int {
    var neg = false
    var y = x
    var digits : [Int] = []
    if x < 0 {
        neg = true
        y = -y
    }
    
    while y != 0 {
        digits.append(y%10)
        y /= 10
    }
    print(digits)
    var ans = 0
    var multiplier = 1
    while !digits.isEmpty {
        ans += digits.last! * multiplier
        multiplier *= 10
        digits.removeLast()
    }
    if ans > Int32.max || ans < Int32.min {
        return 0
    }
    if neg {
        return ans * -1
    }
    else {
        return ans
    }
}
//var a = reverse(-123)
//print(a)

func isPalindrome(_ x: Int) -> Bool {

    var strX = String(x)
    var reversedStrX = String(strX.reversed())
    
    return strX == reversedStrX
}
var g = isPalindrome(121)
print(g)

