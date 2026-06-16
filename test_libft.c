#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	g_total = 0;
static int	g_pass = 0;
static int	g_del_count = 0;

static void	check_int(const char *name, int got, int expected)
{
	g_total++;
	if (got == expected)
	{
		g_pass++;
		printf("[OK]   %s\n", name);
	}
	else
		printf("[FAIL] %s | got: %d | expected: %d\n", name, got, expected);
}

static void	check_size(const char *name, size_t got, size_t expected)
{
	g_total++;
	if (got == expected)
	{
		g_pass++;
		printf("[OK]   %s\n", name);
	}
	else
		printf("[FAIL] %s | got: %zu | expected: %zu\n", name, got, expected);
}

static void	check_str(const char *name, const char *got, const char *expected)
{
	g_total++;
	if ((got == NULL && expected == NULL)
		|| (got != NULL && expected != NULL && ft_strncmp(got, expected,
			ft_strlen(expected) + 1) == 0))
	{
		g_pass++;
		printf("[OK]   %s\n", name);
	}
	else
		printf("[FAIL] %s | got: [%s] | expected: [%s]\n", name,
			got ? got : "NULL", expected ? expected : "NULL");
}

static void	check_ptr(const char *name, void *got, void *expected)
{
	g_total++;
	if (got == expected)
	{
		g_pass++;
		printf("[OK]   %s\n", name);
	}
	else
		printf("[FAIL] %s | got: %p | expected: %p\n", name, got, expected);
}

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	map_first_upper(unsigned int i, char c)
{
	if (i == 0)
		return ((char)ft_toupper(c));
	return (c);
}

static void	iter_change_second(unsigned int i, char *c)
{
	if (i == 1)
		*c = 'X';
}

static void	del_content(void *content)
{
	g_del_count++;
	free(content);
}

static void	print_content(void *content)
{
	if (content)
		((char *)content)[0] = (char)ft_toupper(((char *)content)[0]);
}

static void	*copy_content(void *content)
{
	return (ft_strdup((char *)content));
}

static void	test_ctype(void)
{
	printf("\n=== CTYPE ===\n");
	check_int("ft_isalpha('A')", ft_isalpha('A'), 1);
	check_int("ft_isalpha('z')", ft_isalpha('z'), 1);
	check_int("ft_isalpha('1')", ft_isalpha('1'), 0);
	check_int("ft_isdigit('9')", ft_isdigit('9'), 1);
	check_int("ft_isdigit('a')", ft_isdigit('a'), 0);
	check_int("ft_isalnum('a')", ft_isalnum('a'), 1);
	check_int("ft_isalnum('7')", ft_isalnum('7'), 1);
	check_int("ft_isalnum('@')", ft_isalnum('@'), 0);
	check_int("ft_isascii(127)", ft_isascii(127), 1);
	check_int("ft_isascii(128)", ft_isascii(128), 0);
	check_int("ft_isprint(' ')", ft_isprint(' '), 1);
	check_int("ft_isprint(31)", ft_isprint(31), 0);
	check_int("ft_toupper('a')", ft_toupper('a'), 'A');
	check_int("ft_toupper('A')", ft_toupper('A'), 'A');
	check_int("ft_tolower('Z')", ft_tolower('Z'), 'z');
	check_int("ft_tolower('z')", ft_tolower('z'), 'z');
}

static void	test_memory(void)
{
	char	buf[20];
	char	copy[20];
	char	overlap[20];
	char	*memchr_result;

	printf("\n=== MEMORY ===\n");
	ft_memset(buf, 'A', 5);
	buf[5] = '\0';
	check_str("ft_memset", buf, "AAAAA");
	ft_bzero(buf, 5);
	check_int("ft_bzero", buf[0], 0);
	ft_memset(copy, 0, sizeof(copy));
	ft_memcpy(copy, "libft", 6);
	check_str("ft_memcpy", copy, "libft");
	ft_strlcpy(overlap, "123456789", sizeof(overlap));
	ft_memmove(overlap + 2, overlap, 5);
	check_str("ft_memmove overlap", overlap, "121234589");
	memchr_result = ft_memchr("abcdef", 'd', 6);
	check_str("ft_memchr", memchr_result, "def");
	check_ptr("ft_memchr not found", ft_memchr("abcdef", 'z', 6), NULL);
	check_int("ft_memcmp equal", ft_memcmp("abc", "abc", 3), 0);
	check_int("ft_memcmp diff", ft_memcmp("abc", "abd", 2), 0);
}

static void	test_strings(void)
{
	char	buf[20];
	char	copy[20];
	char	*dup;

	printf("\n=== STRINGS ===\n");
	check_size("ft_strlen", ft_strlen("abc"), 3);
	check_size("ft_strlcpy return", ft_strlcpy(copy, "hello", sizeof(copy)), 5);
	check_str("ft_strlcpy copy", copy, "hello");
	check_size("ft_strlcpy size 0", ft_strlcpy(copy, "world", 0), 5);
	ft_strlcpy(buf, "Rafa", sizeof(buf));
	check_size("ft_strlcat return", ft_strlcat(buf, "42", sizeof(buf)), 6);
	check_str("ft_strlcat result", buf, "Rafa42");
	check_str("ft_strchr", ft_strchr("banana", 'n'), "nana");
	check_str("ft_strrchr", ft_strrchr("banana", 'a'), "a");
	check_ptr("ft_strchr not found", ft_strchr("banana", 'z'), NULL);
	check_int("ft_strncmp equal limit", ft_strncmp("abc", "abd", 2), 0);
	check_int("ft_strncmp zero", ft_strncmp("abc", "xyz", 0), 0);
	check_str("ft_strnstr found", ft_strnstr("hello libft", "libft", 11), "libft");
	check_ptr("ft_strnstr not found by len", ft_strnstr("hello libft", "libft", 5), NULL);
	check_str("ft_strnstr empty needle", ft_strnstr("abc", "", 3), "abc");
	dup = ft_strdup("libft");
	check_str("ft_strdup", dup, "libft");
	free(dup);
}

static void	test_conversion_alloc(void)
{
	int		*zero;
	char	*tmp;

	printf("\n=== CONVERSION / ALLOC ===\n");
	check_int("ft_atoi spaces", ft_atoi(" \t\n-42abc"), -42);
	check_int("ft_atoi plus", ft_atoi("+123"), 123);
	check_int("ft_atoi INT_MIN", ft_atoi("-2147483648"), -2147483647 - 1);
	zero = ft_calloc(5, sizeof(int));
	check_int("ft_calloc first", zero[0], 0);
	check_int("ft_calloc last", zero[4], 0);
	free(zero);
	tmp = ft_itoa(0);
	check_str("ft_itoa 0", tmp, "0");
	free(tmp);
	tmp = ft_itoa(42);
	check_str("ft_itoa 42", tmp, "42");
	free(tmp);
	tmp = ft_itoa(-42);
	check_str("ft_itoa -42", tmp, "-42");
	free(tmp);
	tmp = ft_itoa(-2147483647 - 1);
	check_str("ft_itoa INT_MIN", tmp, "-2147483648");
	free(tmp);
}

static void	test_part2_strings(void)
{
	char	*tmp;
	char	**split;
	char	iter_buf[4];

	printf("\n=== PART 2 STRINGS ===\n");
	tmp = ft_substr("libft", 2, 3);
	check_str("ft_substr middle", tmp, "bft");
	free(tmp);
	tmp = ft_substr("libft", 20, 3);
	check_str("ft_substr start too far", tmp, "");
	free(tmp);
	tmp = ft_strjoin("lib", "ft");
	check_str("ft_strjoin", tmp, "libft");
	free(tmp);
	tmp = ft_strtrim("...Rafa...", ".");
	check_str("ft_strtrim normal", tmp, "Rafa");
	free(tmp);
	tmp = ft_strtrim(".....", ".");
	check_str("ft_strtrim all", tmp, "");
	free(tmp);
	split = ft_split("  oi  rafa  libft  ", ' ');
	check_str("ft_split [0]", split[0], "oi");
	check_str("ft_split [1]", split[1], "rafa");
	check_str("ft_split [2]", split[2], "libft");
	check_ptr("ft_split end", split[3], NULL);
	free_split(split);
	split = ft_split(",,,", ',');
	check_ptr("ft_split only sep", split[0], NULL);
	free_split(split);
	tmp = ft_strmapi("abc", map_first_upper);
	check_str("ft_strmapi", tmp, "Abc");
	free(tmp);
	ft_strlcpy(iter_buf, "abc", sizeof(iter_buf));
	ft_striteri(iter_buf, iter_change_second);
	check_str("ft_striteri", iter_buf, "aXc");
}

static void	test_fd_functions(void)
{
	int		fd;
	ssize_t	read_size;
	char	buf[100];

	printf("\n=== FD FUNCTIONS ===\n");
	fd = open("tmp_fd_test.txt", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0)
	{
		printf("[FAIL] could not open tmp_fd_test.txt\n");
		g_total++;
		return ;
	}
	ft_putchar_fd('A', fd);
	ft_putstr_fd("BC", fd);
	ft_putendl_fd("D", fd);
	ft_putnbr_fd(-2147483647 - 1, fd);
	lseek(fd, 0, SEEK_SET);
	read_size = read(fd, buf, sizeof(buf) - 1);
	if (read_size >= 0)
		buf[read_size] = '\0';
	else
		buf[0] = '\0';
	close(fd);
	unlink("tmp_fd_test.txt");
	check_str("ft_putchar/putstr/putendl/putnbr_fd", buf, "ABCD\n-2147483648");
}

static void	test_bonus_list(void)
{
	t_list	*lst;
	t_list	*copy;
	t_list	*single;

	printf("\n=== BONUS LIST ===\n");
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("one")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("two")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("zero")));
	check_int("ft_lstsize", ft_lstsize(lst), 3);
	check_str("ft_lstlast", (char *)ft_lstlast(lst)->content, "two");
	ft_lstiter(lst, print_content);
	check_str("ft_lstiter first", (char *)lst->content, "Zero");
	copy = ft_lstmap(lst, copy_content, del_content);
	check_int("ft_lstmap size", ft_lstsize(copy), 3);
	check_str("ft_lstmap last", (char *)ft_lstlast(copy)->content, "Two");
	g_del_count = 0;
	single = ft_lstnew(ft_strdup("delete me"));
	ft_lstdelone(single, del_content);
	check_int("ft_lstdelone del count", g_del_count, 1);
	g_del_count = 0;
	ft_lstclear(&lst, del_content);
	check_ptr("ft_lstclear lst NULL", lst, NULL);
	check_int("ft_lstclear del count", g_del_count, 3);
	ft_lstclear(&copy, del_content);
}

int	main(void)
{
	test_ctype();
	test_memory();
	test_strings();
	test_conversion_alloc();
	test_part2_strings();
	test_fd_functions();
	test_bonus_list();
	printf("\nRESULT: %d/%d tests passed\n", g_pass, g_total);
	if (g_pass == g_total)
		return (0);
	return (1);
}
