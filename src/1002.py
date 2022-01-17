# -*- coding: utf-8 -*-
# [BoJ 1002] 터렛 : https://www.acmicpc.net/problem/1002
# writer : Shinhyeok Hwang


if  __name__ == '__main__':
    N = int(input())
    params = [map(int, input().split()) for _ in range(N)] # x1, y1, r1, x2, y2, r2

    print(N)
    for param in params:
        print(*param)
