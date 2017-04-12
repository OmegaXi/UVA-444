#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace std;

char* strrev( char* str )
{
	int s = 0,e = strlen(str)-1;
	while ( s < e ) {
		swap( str[s], str[e] );
		s ++;e --;
	}
	return str;
}

char str[1000];
char rev[1000];

int main()
{
	while ( gets(str) ) {
		int v,l = strlen(str);
		if ( str[0] >= '0' && str[0] <= '9' ) {
			strrev(str);
			int count = 0;
			for ( int i = 0 ; i < l ; i += 2 ) {
				v = (str[i]-'0')*10+str[i+1]-'0';
				if ( str[i] == '1' ) {
					v = v*10+str[i+2]-'0';
					++ i;
				}
				rev[count ++] = v;
			}rev[count] = 0;
			cout << rev << endl;
		}else {
			int count = 0;
			for ( int i = 0 ; i < l ; ++ i ) {
				if ( str[i] > 99 ) {
					rev[count ++] = str[i]/100+'0';
					str[i] %= 100;
				}
				rev[count ++] = str[i]/10+'0';
				rev[count ++] = str[i]%10+'0';
			}rev[count] = 0;
			strrev(rev);
			cout << rev << endl;
		}
	}
	
	return 0;
}

