#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through rows
    for (int row = 0; row < height; row++)
    {
        // Loop through columns
        for (int column = 0; column < width; column++)
        {
            int redValue = image[row][column].rgbtRed;
            int greenValue = image[row][column].rgbtGreen;
            int blueValue = image[row][column].rgbtBlue;

            // Calculate the average and round it
            int avgGrayValue = round((redValue + greenValue + blueValue) / 3.0);

            // Change pixel color to the new grayscale value
            image[row][column].rgbtRed = avgGrayValue;
            image[row][column].rgbtGreen = avgGrayValue;
            image[row][column].rgbtBlue = avgGrayValue;
        }
    }
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            // Get original RGB values
            int originalRed = image[row][column].rgbtRed;
            int originalGreen = image[row][column].rgbtGreen;
            int originalBlue = image[row][column].rgbtBlue;

            // Compute sepia values
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // Cap the values at 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Update pixel with sepia values
            image[row][column].rgbtRed = sepiaRed;
            image[row][column].rgbtGreen = sepiaGreen;
            image[row][column].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all rows
    for (int row = 0; row < height; row++)
    {
        // Loop through columns up to the midpoint
        for (int column = 0; column < width / 2; column++)
        {
            // Store temp
            RGBTRIPLE temp = image[row][column];
            // Move the right column to the left
            image[row][column] = image[row][width - column - 1];
            // Move the left column to the right
            image[row][width - column - 1] = temp;
        }
    }
}

// Blur image - box blur technique
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Step 1: Create a copy of the original image
    RGBTRIPLE copy[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            copy[row][column] = image[row][column];
        }
    }

    // Step 2: Iterate over each pixel in the image
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            // Initialize sums and count for averaging
            int red_sum = 0;
            int green_sum = 0;
            int blue_sum = 0;
            int count = 0;

            // Step 3: Iterate over neighboring pixels
            for (int row_offset = -1; row_offset <= 1; row_offset++)
            {
                for (int col_offset = -1; col_offset <= 1; col_offset++)
                {
                    int neighbor_row = row + row_offset;
                    int neighbor_column = column + col_offset;

                    // Check if neighbor is within bounds
                    if (neighbor_row >= 0 && neighbor_row < height && neighbor_column >= 0 &&
                        neighbor_column < width)
                    {
                        red_sum += copy[neighbor_row][neighbor_column].rgbtRed;
                        green_sum += copy[neighbor_row][neighbor_column].rgbtGreen;
                        blue_sum += copy[neighbor_row][neighbor_column].rgbtBlue;
                        count++;
                    }
                }
            }

            // Step 4: Calculate average and update the image
            image[row][column].rgbtRed = round((float) red_sum / count);
            image[row][column].rgbtGreen = round((float) green_sum / count);
            image[row][column].rgbtBlue = round((float) blue_sum / count);
        }
    }
}
