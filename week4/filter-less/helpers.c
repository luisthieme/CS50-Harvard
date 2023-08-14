#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE temp = image[i][j];
            int avg = (temp.rgbtBlue + temp.rgbtGreen + temp.rgbtRed) / 3;
            temp.rgbtBlue = avg;
            temp.rgbtGreen = avg;
            temp.rgbtRed = avg;
            image[i][j] = temp;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE temp = image[i][j];
            int sepiaRed = (int) .393 * temp.rgbtRed + .769 * temp.rgbtGreen + .189 * temp.rgbtBlue;

            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            int sepiaGreen = (int) .349 * temp.rgbtRed + .686 * temp.rgbtGreen + .168 * temp.rgbtBlue;

            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            int sepiaBlue = (int) .272 * temp.rgbtRed + .534 * temp.rgbtGreen + .131 * temp.rgbtBlue;

            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            temp.rgbtBlue = sepiaBlue;
            temp.rgbtGreen = sepiaGreen;
            temp.rgbtRed = sepiaRed;
            image[i][j] = temp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp1 = image[i][j];
            RGBTRIPLE temp2 = image[i][width - j - 1];
            image[i][j] = temp2;
            image[i][width - j - 1] = temp1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            RGBTRIPLE topLeftPixel = image[i - 1][j -1];
            RGBTRIPLE topMidPixel = image[i - 1][j]; 
            RGBTRIPLE topRightPixel = image[i - 1][j + 1];

            RGBTRIPLE midLeftPixel = image[i][j - 1];
            RGBTRIPLE midMidPixel = image[i][j];
            RGBTRIPLE midRightPixel = image[i][j + 1];

            RGBTRIPLE bottomLeftPixel = image[i + 1][j - 1];
            RGBTRIPLE bottomMidPixel = image[i + 1][j];
            RGBTRIPLE bottomRightPixel = image[i + 1][j + 1];

            int bluredRed = (topLeftPixel.rgbtRed + topMidPixel.rgbtRed + topRightPixel.rgbtRed + midLeftPixel.rgbtRed + midMidPixel.rgbtRed + midRightPixel.rgbtRed + bottomLeftPixel.rgbtRed + bottomMidPixel.rgbtRed + bottomRightPixel.rgbtRed) / 9;
            int bluredGreen = (topLeftPixel.rgbtGreen + topMidPixel.rgbtGreen + topRightPixel.rgbtGreen + midLeftPixel.rgbtGreen + midMidPixel.rgbtGreen + midRightPixel.rgbtGreen + bottomLeftPixel.rgbtGreen + bottomMidPixel.rgbtGreen + bottomRightPixel.rgbtGreen) / 9;
            int bluredBlue = (topLeftPixel.rgbtBlue + topMidPixel.rgbtBlue + topRightPixel.rgbtBlue + midLeftPixel.rgbtBlue + midMidPixel.rgbtBlue + midRightPixel.rgbtBlue + bottomLeftPixel.rgbtBlue + bottomMidPixel.rgbtBlue + bottomRightPixel.rgbtBlue) / 9;

            image[i][j].rgbtRed = bluredRed;
            image[i][j].rgbtGreen = bluredGreen;
            image[i][j].rgbtBlue = bluredBlue;
        }
    }
    return;
}
