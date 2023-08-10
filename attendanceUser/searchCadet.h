#pragma once

//Syntax: string mostSimilar = findMostSimilarString(unrecognised, closest match);

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

size_t levenshteinDistance(const std::string& str1, const std::string& str2);

// Function to calculate the Levenshtein distance between two strings
size_t levenshteinDistance(const std::string& str1, const std::string& str2) {
    const size_t m = str1.length();
    const size_t n = str2.length();

    // Create a 2D table to store the distances
    std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1, 0));

    for (size_t i = 0; i <= m; ++i) {
        for (size_t j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
    }

    return dp[m][n];
}

// Function to find the most similar string in the vector
std::string findMostSimilarString(const std::string& target, const std::vector<std::string>& strings) {
    size_t minDistance = INT_MAX;
    std::string mostSimilarString;

    for (const std::string& str : strings) {
        size_t distance = levenshteinDistance(target, str);
        if (distance < minDistance) {
            minDistance = distance;
            mostSimilarString = str;
        }
    }

    return mostSimilarString;
}