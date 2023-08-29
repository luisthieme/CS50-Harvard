#include "helpers.h"
#include <math.h>
#include <stdio.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
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

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp1 = image[i][j];
            RGBTRIPLE temp2 = image[i][width - j - 1];
            image[i][j] = temp2;
            image[i][width - j - 1] = temp1;
        }
    }

    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE topLeftPixel = image[i - 1][j - 1];
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

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE topLeftPixel = image[i - 1][j - 1];
            RGBTRIPLE topMidPixel = image[i - 1][j];
            RGBTRIPLE topRightPixel = image[i - 1][j + 1];

            RGBTRIPLE midLeftPixel = image[i][j - 1];
            RGBTRIPLE midMidPixel = image[i][j];
            RGBTRIPLE midRightPixel = image[i][j + 1];

            RGBTRIPLE bottomLeftPixel = image[i + 1][j - 1];
            RGBTRIPLE bottomMidPixel = image[i + 1][j];
            RGBTRIPLE bottomRightPixel = image[i + 1][j + 1];

            int gxRed = topLeftPixel.rgbtRed * (-1) + topRightPixel.rgbtRed + midLeftPixel.rgbtRed * (-2) + midLeftPixel.rgbtRed * 2 + bottomLeftPixel.rgbtRed * (-1) + bottomRightPixel.rgbtRed;
            int gxGreen = topLeftPixel.rgbtGreen * (-1) + topRightPixel.rgbtGreen + midLeftPixel.rgbtGreen * (-2) + midLeftPixel.rgbtGreen * 2 + bottomLeftPixel.rgbtGreen * (-1) + bottomRightPixel.rgbtGreen;
            int gxBlue = topLeftPixel.rgbtBlue * (-1) + topRightPixel.rgbtBlue + midLeftPixel.rgbtBlue * (-2) + midLeftPixel.rgbtBlue * 2 + bottomLeftPixel.rgbtBlue * (-1) + bottomRightPixel.rgbtBlue;

            int gyRed = topLeftPixel.rgbtRed * (-1) + bottomLeftPixel.rgbtRed + topMidPixel.rgbtRed * (-2) + topMidPixel.rgbtRed * 2 + topRightPixel.rgbtRed * (-1) + bottomRightPixel.rgbtRed;
            int gyGreen = topLeftPixel.rgbtGreen * (-1) + bottomLeftPixel.rgbtGreen + topMidPixel.rgbtGreen * (-2) + topMidPixel.rgbtGreen * 2 + topRightPixel.rgbtGreen * (-1) + bottomRightPixel.rgbtGreen;
            int gyBlue = topLeftPixel.rgbtBlue * (-1) + bottomLeftPixel.rgbtBlue + topMidPixel.rgbtBlue * (-2) + topMidPixel.rgbtBlue * 2 + topRightPixel.rgbtBlue * (-1) + bottomRightPixel.rgbtBlue;

            int edgeRed = (int)sqrt(pow(gxRed, 2) + pow(gyRed, 2));

            if (edgeRed > 255)
            {
                edgeRed = 255;
            }
            else if (edgeRed < 0)
            {
                edgeRed = 0;
            }

            int edgeGreen = round(sqrt(pow(gxGreen, 2) + pow(gxGreen, 2)));

            if (edgeGreen > 255)
            {
                edgeGreen = 255;
            }
            else if (edgeGreen < 0)
            {
                edgeGreen = 0;
            }

            int edgeBlue = round(sqrt(pow(gxBlue, 2) + pow(gyBlue, 2)));

            if (edgeBlue > 255)
            {
                edgeBlue = 255;
            }
            else if (edgeBlue < 0)
            {
                edgeBlue = 0;
            }

            temp[i][j].rgbtRed = edgeRed;
            temp[i][j].rgbtGreen = edgeGreen;
            temp[i][j].rgbtBlue = edgeBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}
