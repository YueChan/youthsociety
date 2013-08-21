import math
import itertools

def part1(a, base):
    x, y = 0, a
    L = []
    while y:
        L.append(x)
        x, y = y % base, y / base
    L.append(x)
    return L

def part2(b, base):
    x, y = 0, b
    M = []
    while y:
        M.append(x)
        x, y = int(math.floor(y * base)), y * base - int(math.floor(y * base))
    M.append(x)
    return M

def dec_to_any():
    '''This function also only supports non-negative numbers'''

    num = input('Please enter a decimal number:')
    base = input('Please enter the base:')
    L = part1(int(math.floor(num)), base)[1:]
    L.reverse()
    print ''.join(str(i) for i in L) + '.' + ''.join(str(j) for j in part2(num - int(math.floor(num)), base)[1:])

dec_to_any()
