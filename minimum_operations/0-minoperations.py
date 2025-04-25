#!/usr/bin/python3

"""Min Operation Module"""


def minOperations(n):
    if n < 2:
        return 0

    total = 0
    div = 2

    while n > 1:
        while n % div == 0:
            total += div
            n //= div
        div += 1

    return total
