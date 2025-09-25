#!/usr/bin/python3
"""
Given a pile of coins of different values,
determine the fewest number of coins needed to meet a
given amount total
"""


def makeChange(coins, total):
    # Si le total est 0 ou moins, aucune pièce n'est nécessaire
    if total <= 0:
        return 0

    # Initialiser un tableau pour suivre le nombre minimum de pièces
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Aucun besoin de pièce pour atteindre un total de 0

    # Pour chaque montant de 1 à 'total', calculer le nombre minimal de pièces
    for montant in range(1, total + 1):
        for coin in coins:
            if coin <= montant:
                dp[montant] = min(dp[montant], dp[montant - coin] + 1)

    # Si dp[total] reste infini, le total est impossible à atteindre
    return dp[total] if dp[total] != float('inf') else -1
