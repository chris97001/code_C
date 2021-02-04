#include<stdio.h>

int main()
{
    int year,weight,Age;
    float height,BMI;
    scanf("%d %f %d",&year,&height,&weight);
    float hi=height/100;
    BMI=weight/(hi*hi);
    Age=2020-year+1;
    printf("Age = %d\n",Age);
    printf("Height = %3.0f",height);
    printf("cm\n");
    printf("Weight = %d",weight);
    printf("kg\n");
    printf("BMI = %.1f\n",BMI);
    if(Age<19 || Age>36)
    {
        printf("Not a Draftee (age < 19 or age > 36 years old)\n");
        printf("No need to perform Military Service");
    }
        
    else
    {
        if (BMI>=17 && BMI<=31)
    {
        printf("Physical Status of Regular Service Draftees\n");
        if (year<=1993)
            printf("1 year of Regular Service");
        else
            printf("4 months of Regular Service");
    }
    else if((BMI>=16.5 && BMI <17)||(BMI>31 && BMI<=31.5))
    {
        printf("Physical Status of Substitute Service Draftees\n");
        if(year<=1993)
            printf("Substitute Services");
        else
            printf("Replacement Service");
    }
    else
    {
        printf("Physical Status of Military Service Exemption\n");
        printf("Exemption from Military Service");
    }
    }
    
    return 0;
}
