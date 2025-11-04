#include <bits/stdc++.h>
using namespace std;

const int maxn=1024;

struct Pixel
{
    uint8_t R,G,B;
};

struct imageRGB
{
    Pixel image[maxn][maxn];
};

int main()
{
    ofstream outF("Raboti.ppm");
    imageRGB img;
    double cx=maxn/2.0;
    double cy=maxn/2.0;
    double max_dist=sqrt(cx*cx+cy*cy);
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<maxn;j++)
        {
            double dx=i-cx;
            double dy=j-cy;
            double dist=sqrt(dx*dx+dy*dy);
            double t=dist/max_dist;
            Pixel p;
            p.R=0;
            p.G=static_cast<uint8_t>(255.0*t);
            p.B=0;
            img.image[j][i]=p;
        }
    }
    outF << "P3" << '\n' << maxn << ' ' << maxn << '\n' << 255 << '\n';
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<maxn;j++)
        {
            int Gval=int(img.image[j][i].G);
            outF<<int(img.image[j][i].R)<<" "<<255-Gval<<" "<<int(img.image[j][i].B)<<endl;
        }
    }
    outF.close();
    return 0;
}
