#!/usr/bin/python3
"""
0-rain module

This module provides a single function `rain(walls)` that calculates
how many square units of rainwater can be trapped between walls after it rains.

Each wall is represented by a non-negative integer in a list,
where each integer corresponds to the height of a wall of unit width 1.
"""


def rain(walls):
    """
    Given a list of non-negative integers representing wall heights,
    compute how much rainwater will be retained after it rains.

    Args:
    - walls (List[int]): List of wall heights

    Returns:
    - int: Total units of water retained
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left = 0
    right = n - 1
    left_max = walls[left]
    right_max = walls[right]
    water = 0

    while left < right:
        if walls[left] < walls[right]:
            left += 1
            left_max = max(left_max, walls[left])
            water += max(0, left_max - walls[left])
        else:
            right -= 1
            right_max = max(right_max, walls[right])
            water += max(0, right_max - walls[right])

    return water
