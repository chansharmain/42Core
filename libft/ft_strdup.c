#include <stddef.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
// remove above

char *ft_strdup(const char *s)
{
    char *dup;
    int i;

    i = 0;
    dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (dup == NULL)
        return (NULL);
    while (s[i] != '\0')
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

#include <stdio.h>
#include <string.h>
int	main()
{
	char *s = "hello";

	printf("ft_strdup:%s\n", ft_strdup(s));
	printf("strdup:%s\n", strdup(s));
}