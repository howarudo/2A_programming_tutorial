// 学籍番号： J4220368
// 名前：タンクルンホワルド
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    FILE *fp;
    fp = fopen("namelist.txt", "r");
    if (fp == NULL) {
        // check if file could be opened
        printf("Failed to open file!");
        return 1;
    }
    int age;
    double height, weight;
    double n = 0.0;
    int minAge = 9999, maxAge = 0, sumAge = 0, sumSquaredAge= 0;
    double minHeight = 9999.0, maxHeight = 0.0, sumHeight = 0.0, sumSquaredHeight = 0.0;
    double minWeight = 9999.0, maxWeight = 0.0, sumWeight = 0.0, sumSquaredWeight = 0.0;
    while (fscanf(fp, "%*[^,],%d,%lf,%lf\n", &age, &height, &weight) > 0) {
        // minimum of age, height and weight
        minAge = minAge > age ? age : minAge;
        minHeight = minHeight > height ? height : minHeight;
        minWeight = minWeight > weight ? weight : minWeight;

        // maximum of age, height and weight
        maxAge = maxAge < age ? age : maxAge;
        maxHeight = maxHeight < height ? height : maxHeight;
        maxWeight = maxWeight < weight ? weight : maxWeight;

        // store the sum of age. Used to calculate average
        sumAge += age;
        sumHeight += height;
        sumWeight += weight;

        // store the squared sum to calculate stdev later
        sumSquaredAge += age * age;
        sumSquaredHeight += height * height;
        sumSquaredWeight += weight * weight;
        n++;
    }
    // stdev caluclated using sqrt(sum of squared/n - mean^2)
    printf("Age : (max,min,mean,stdev) = (%d,%d,%lf,%lf)\n", maxAge, minAge, sumAge/n, sqrt((sumSquaredAge/n - (sumAge/n)*(sumAge/n))));
    printf("Height : (max,min,mean,stdev) = (%lf,%lf,%lf,%lf)\n", maxHeight, minHeight, sumHeight/n, sqrt((sumSquaredHeight/n - (sumHeight/n)*(sumHeight/n))));
    printf("Weight : (max,min,mean,stdev) = (%lf,%lf,%lf,%lf)\n", maxWeight, minWeight, sumWeight/n, sqrt((sumSquaredWeight/n - (sumWeight/n)*(sumWeight/n))));
    fclose(fp);
    return 0;
}
