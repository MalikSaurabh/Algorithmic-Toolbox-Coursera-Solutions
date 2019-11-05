# python3

import sys, time, random

def lcs2(a, b):
    lcsmat = [[0 for x in range(len(a) + 1)] for y in range(len(b) + 1)]
    ins = [0]*6
    for y in range(1, len(b) + 1):
        for x in range(1, len(a) + 1):
            ins[0] = lcsmat[y][x-1]
            ins[1] = lcsmat[y-1][x]
            ins[2] = lcsmat[y-1][x-1]
            ins[3] = lcsmat[y][x]
            mis = lcsmat[y-1][x-1]
            mat = lcsmat[y-1][x-1] + 1
            if a[x-1] == b[y-1]:
                lcsmat[y][x] = max(max(ins), mat)
            else:
                lcsmat[y][x] = max(max(ins), mis)

    return lcsmat[-1][-1]

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
    print(lcs2(a, b))