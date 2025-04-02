#!/usr/bin/python3

"""
This module contains a function that determines if all boxes can be unlocked
"""

def canUnlockAll(boxes):
    """
    Determines if all boxes can be unlocked.

    Args:
        boxes (list): A list of lists representing boxes and their keys.

    Returns:
        bool: True if all boxes can be unlocked, False otherwise.
    """
    unlocked = [0]
    keys = []

    while unlocked:
        current_box = unlocked.pop()
        for key in boxes[current_box]:
            if key not in keys and key < len(boxes):
                keys.append(key)
                unlocked.append(key)

    return len(keys) == len(boxes)