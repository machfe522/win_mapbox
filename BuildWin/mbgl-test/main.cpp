
#include <curl/curl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>



void print_cookies(CURL *curl)
{
	CURLcode res;
	struct curl_slist *cookies;
	struct curl_slist *nc;
	int i;

	printf("Cookies, curl knows:\n");
	res = curl_easy_getinfo(curl, CURLINFO_COOKIELIST, &cookies);
	if (res != CURLE_OK) {
		fprintf(stderr, "Curl curl_easy_getinfo failed: %s\n",
			curl_easy_strerror(res));
		exit(1);
	}
	nc = cookies;
	i = 1;
	while (nc) {
		printf("[%d]: %s\n", i, nc->data);
		nc = nc->next;
		i++;
	}
	if (i == 1) {
		printf("(none)\n");
	}
	curl_slist_free_all(cookies);
}

const char* cookiefile = "D:\\Project\\cookie.txt";

struct MemoryStruct
{
	char *memory;
	size_t size;
	MemoryStruct()
	{
		memory = (char *)malloc(1);
		size = 0;
	}
	~MemoryStruct()
	{
		free(memory);
		memory = NULL;
		size = 0;
	}
};

size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;
	//struct MemoryStruct *mem = (struct MemoryStruct *)data;

	//mem->memory = (char *)realloc(mem->memory, mem->size + realsize + 1);
	//if (mem->memory)
	//{
	//	memcpy(&(mem->memory[mem->size]), ptr, realsize);
	//	mem->size += realsize;
	//	mem->memory[mem->size] = 0;
	//}
	return realsize;
}



bool requestCode()
{
	CURL *handle = NULL;
	handle = curl_easy_init();

	std::string url = "https://api.mapbox.com/styles/v1/mapbox/streets-v11?access_token=pk.eyJ1IjoibWFtYWNoZmUiLCJhIjoiY2p1dzBndXRjMDdjcDN5cGI2d2duM3d2byJ9.BPbVcece6cQABmqi0CvgZQ"; 
	//待请求的页面
	 
	//(curl_easy_setopt(handle, CURLOPT_PRIVATE, this));
	//(curl_easy_setopt(handle, CURLOPT_ERRORBUFFER, error));
	(curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, false));//设定为不验证证书和HOST
	(curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, false));

	(curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1)); //允许重定向
	(curl_easy_setopt(handle, CURLOPT_URL, url.c_str()));
	(curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback));
	(curl_easy_setopt(handle, CURLOPT_WRITEDATA, NULL));
	(curl_easy_setopt(handle, CURLOPT_HEADERFUNCTION, NULL));
	(curl_easy_setopt(handle, CURLOPT_HEADERDATA, NULL));
#if LIBCURL_VERSION_NUM >= ((7) << 16 | (21) << 8 | 6) // Renamed in 7.21.6
	//(curl_easy_setopt(handle, CURLOPT_ACCEPT_ENCODING, "gzip, deflate"));
#else
	handleError(curl::easy_setopt(handle, CURLOPT_ENCODING, "gzip, deflate"));
#endif
	(curl_easy_setopt(handle, CURLOPT_USERAGENT, "MapboxGL/1.0"));
	//(curl_easy_setopt(handle, CURLOPT_SHARE, context->share));
	(curl_easy_setopt(handle, CURLOPT_VERBOSE, true));     //调试信息
	 

	 


	CURLcode res = curl_easy_perform(handle);  //执行请求
	

	long res_code = 0;
	res = curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &res_code);
	//正确响应后，请请求转写成本地文件的文件
	if ((res == CURLE_OK) && (res_code == 200 || res_code == 201))
	{

		std::string str;;
	}


	curl_easy_cleanup(handle);

	return true;
}
 
int main(int argc, char **argv)
{


	CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
	if (CURLE_OK != res)
	{
		return 1;
	}
	
	requestCode();
	
	curl_global_cleanup();

	return 0;


}
