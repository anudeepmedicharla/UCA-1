#include <stdio.h>
#include <string.h>
unsigned char charset[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

unsigned char revchar(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
		ch = ch - 'A';
	else if(ch >= 'a' && ch <= 'z')
		ch = ch - 'a' + 26;
	else if(ch >= '0' && ch <= '9')
		ch = ch - '0' + 52;
	else if(ch == '+')
		ch = 62;
	else if(ch == '/')
		ch = 63;
	return ch;
}

int encode(unsigned char in[], unsigned char out[], int length, int new_flag)
{
	int idx1, idx2, blk, left_over;
	blk = (length / 3) * 3;
	for(idx1 = 0, idx2 = 0; idx1 < blk; idx1 += 3, idx2 += 4)
	{
		out[idx2] = charset[(in[idx1] >> 2)];
		out[idx2 + 1] = charset[((in[idx1] & 0x03) << 4) + (in[idx1 + 1] >> 4)];
		out[idx2 + 2] = charset[((in[idx1 + 1] & 0x0F) << 2) + (in[idx1 + 2] >> 6)];
		out[idx2 + 3] = charset[((in[idx1 + 2] & 0x3F))];
		if(!(idx2 % 77) && new_flag)
		{
			out[idx2 + 4] == '\n';
			idx2++;
		}

	}
	left_over = length % 3;
	if(left_over == 1)
	{
		out[idx2] = charset[(in[idx1] >> 2)];
		out[idx2 + 1] = charset[((in[idx1] & 0x03) << 4)];
		out[idx2 + 2] = '=';
		out[idx2 + 3] = '=';
		idx2 += 4;
	}
	else if(left_over == 2)
	{
		out[idx2] = charset[(in[idx1] >> 2)];
		out[idx2 + 1] = charset[((in[idx1] & 0x03) << 4) + (in[idx1 + 1] >> 4)];
		out[idx2 + 2] = charset[((in[idx1 + 1] & 0x0F) << 2)];
		out[idx2 + 3] = '=';
		idx2 += 4;
	}
	out[idx2] = '\0';
	return idx2;

}

int decode(unsigned char in[],unsigned char out[], int length)
{
	if(in[length-1] == '=')
		length--;
	if(in[length-1] == '=')
		length--;
	int idx1, idx2, blk, left_over;
	blk = (length / 4) * 4;
	for(idx1 = 0, idx2 = 0; idx2 < blk; idx1 += 3, idx2 += 4)
	{
		out[idx1] = (revchar(in[idx2]) << 2) + (revchar((in[idx2 + 1] & 0x30)) >> 4);
		out[idx1 + 1] = (revchar(in[idx2 + 1]) << 4) + (revchar(in[idx2 + 2]) >> 2);
		out[idx1 + 2] = (revchar(in[idx2 + 2]) << 6) + (revchar(in[idx2 + 3]));
	}

	left_over = length % 4;
	
	if(left_over == 2)
	{
		out[idx1] = (revchar(in[idx2]) << 2) + (revchar((in[idx2 + 1] & 0x30)) >> 4);
		out[idx1 + 1] = (revchar(in[idx2 + 1]) << 4);
		idx1 += 2;
	}

	if(left_over == 3)
	{
		out[idx1] = (revchar(in[idx2]) << 2) + (revchar((in[idx2 + 1] & 0x30)) >> 4);
		out[idx1 + 1] = (revchar(in[idx2 + 1]) << 4) + (revchar(in[idx2 + 2]) >> 2);
		out[idx1 + 2] = (revchar(in[idx2 + 2]) << 6);
	}

	out[idx1] = '\0';
	return idx1;
}


int main() 
{  
   unsigned char text1[]={"man"}, 
                 //text2[]={"3.14159"}, 
                 //code1[]={"QmFzZSA2NC4="}, 
                 //code2[]={"YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXo="}, 
                 out[1024], out2[1024]; 

   
   encode(text1,out,strlen(text1),0); 
   puts(out); 
   //encode(text2,out,strlen(text2),0); 
   //puts(out);
   decode(out, out2,strlen(out)); 
   puts(out2); 
   //decode(code2,out,strlen(code2)); 
   //puts(out);  
   return 0;
}	