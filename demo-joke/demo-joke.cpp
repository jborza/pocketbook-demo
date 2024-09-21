#include "inkview.h"
#include "curl/curl.h"
#include <math.h>

static ifont *font;
static const int kFontSize = 32;
static int y_log;

static void log_message(const char *msg)
{
	DrawTextRect(0, y_log, ScreenWidth(), kFontSize, msg, ALIGN_LEFT);
	PartialUpdate(0, y_log, ScreenWidth(), y_log + kFontSize + 2);
	y_log += kFontSize + 2;
}


// HTTP request + result stored in memory
static void http_request_01(void)
{
	char buffer[2048];

	const char *url = "https://v2.jokeapi.dev/joke/Any?format=txt";
	int retsize;
	char *cookie = NULL;
	char *post = NULL;

	snprintf(buffer, sizeof(buffer), "HTTP Request to %s", url);
	log_message(buffer);

	void *result = QuickDownloadExt(url, &retsize, 15, cookie, post);

	snprintf(buffer, sizeof(buffer), "Response size: %d", retsize);
	log_message(buffer);

	log_message("Response content:");
	snprintf(buffer, sizeof(buffer), "Response content: %.1024s", (char *)result);
	log_message(buffer);

	free(result);
}

static int main_handler(int event_type, int param_one, int param_two)
{
	if (EVT_INIT == event_type) {
    	font = OpenFont("LiberationSans", kFontSize, 0);
    	SetFont(font, BLACK);

    	ClearScreen();
    	FullUpdate();

    	y_log = 0;

    	log_message("Starting application...");
    	http_request_01();
    	log_message("End of application.");

    	FullUpdate();
    }
    else if (EVT_KEYPRESS == event_type) {
    	CloseFont(font);
        CloseApp();
    }

    return 0;
}


int main (int argc, char* argv[])
{
    InkViewMain(main_handler);
    return 0;
}
