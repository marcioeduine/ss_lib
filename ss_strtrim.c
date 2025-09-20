#include "ss_lib.h"

text	ss_strtrim(const text s, const text charset)
{
	number	start;
	number	end;

	if (!s)
		return (0);
	start = 0;
	end = ss_strlen(s);
	while (s[start] && ss_strchr(charset, s[start]))
		start++;
	while (end > start && ss_strrchr(charset, s[end - 1]))
		end--;
	return (ss_substr(s, start, end - start));
}
