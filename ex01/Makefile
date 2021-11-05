.PHONY:	all re clean fclean distclean
.SUFFIX: .cpp .o

NAME :=	bureaucrat

SRCS :=	main.cpp \
		Bureaucrat.cpp \
		Form.cpp \
		GradeTooHighExceptionBase.cpp \
		GradeTooLowExceptionBase.cpp \

INCS := Bureaucrat.hpp \
		Form.hpp \
		Utils.hpp \
		GradeTooHighExceptionBase.hpp \
		GradeTooLowExceptionBase.hpp \

ifeq ($(shell uname), Linux)
CXX :=	g++
else
CXX :=	clang++
endif

LD := $(CXX)

CXX_FLAGS := -g3 -Wall -Wextra -Werror -std=c++98 -fsanitize=address -fsanitize=undefined
LD_FLAGS := -g3 -Wall -Wextra -Werror -std=c++98 -fsanitize=address -fsanitize=undefined

OBJS :=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(LD) $(LD_FLAGS) -o $@ $(OBJS)

%.o: %.cpp	$(INCS)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

distclean:	fclean

re: distclean all
