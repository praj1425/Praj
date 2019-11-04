//How to add two largest vectors by Parallel execution

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<omp.h>
using namespace std;
#define MAX 100
int main()
{
int a[MAX],b[MAX],c[MAX],i;
printf("\n First Vector:\t");

#pragma omp parallel for
for(i=0;i<MAX;i++)
	{
		a[i]=rand()%1000;
	}


for(i=0;i<MAX;i++)
	{
		printf("%d\t",a[i]);
	}

printf("\n Second Vector:\t");


#pragma omp parallel for
for(i=0;i<MAX;i++)
	{
		b[i]=rand()%1000;
	}

for(i=0;i<MAX;i++)
	{
		printf("%d\t",b[i]);
	}

printf("\n Parallel-Vector Addition:(a,b,c)\t");



#pragma omp parallel for
for(i=0;i<MAX;i++)
	{
		c[i]=a[i]+b[i];
	}

for(i=0;i<MAX;i++)
	{
		printf("\n%d\t%d\t%d",a[i],b[i],c[i]);
	}
}



/*

guest-bvoaff@C04L0809:~$ g++ par_add_large_vectors.cpp -fopenmp
guest-bvoaff@C04L0809:~$ ./a.out

 First Vector:	383	777	67	58	393	919	537	413	980	729	582	814	434	43	87	276	788	403	754	932	676	739	226	94	539	915	335	386	492	649	421	362	27	690	59	763	926	426	736	368	429	530	123	135	929	802	69	198	324	315	167	456	11	42	229	373	421	784	370	526	873	857	545	367	364	750	808	178	584	651	399	60	368	12	586	886	793	540	172	211	567	782	862	22	91	956	862	170	996	281	305	925	84	327	336	505	846	313	124	895
 Second Vector:	570	219	528	732	503	270	708	340	796	618	846	555	488	228	841	350	193	500	34	764	124	914	987	856	743	491	227	365	859	936	432	551	437	228	275	407	474	121	858	395	29	237	235	793	818	428	143	11	928	529	795	378	467	601	97	902	317	492	652	756	301	280	771	481	675	709	927	567	856	497	353	586	965	306	683	434	286	441	865	689	444	619	440	729	31	117	97	624	871	829	19	368	715	149	723	245	451	921	379	764
*/

