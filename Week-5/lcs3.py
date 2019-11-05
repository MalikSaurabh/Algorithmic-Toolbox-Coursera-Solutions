# python3

import sys, time, random

def lcs3(a, b, c):
    lcsmat = [[[0 for x in range(len(a) + 1)] for y in range(len(b) + 1)] for z in range(len(c) + 1)]
    ins = [0]*6
    for z in range(1, len(c) + 1):
        for y in range(1, len(b) + 1):
            for x in range(1, len(a) + 1):
                ins[0] = lcsmat[z][y][x-1]
                ins[1] = lcsmat[z][y-1][x]
                ins[2] = lcsmat[z][y-1][x-1]
                ins[3] = lcsmat[z-1][y][x]
                ins[4] = lcsmat[z-1][y][x-1]
                ins[5] = lcsmat[z-1][y-1][x]
                mis = lcsmat[z-1][y-1][x-1]
                mat = lcsmat[z-1][y-1][x-1] + 1
                if a[x-1] == b[y-1] == c[z-1]:
                    lcsmat[z][y][x] = max(max(ins), mat)
                else:
                    lcsmat[z][y][x] = max(max(ins), mis)

    return lcsmat[-1][-1][-1]
if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    an = data[0]
    data = data[1:]
    a = data[:an]
    data = data[an:]
    bn = data[0]
    data = data[1:]
    b = data[:bn]
    data = data[bn:]
    cn = data[0]
    data = data[1:]
    c = data[:cn]
    print(lcs3(a, b, c))