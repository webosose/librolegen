# WILL NOT BE PUBLISHED
OBJDIR := $(CUSTOM_BUILD_TYPE)-$(CUSTOM_PLATFORM)
LUNA_STAGING ?= $(HOME)/Local


# ------------------------------------------------------------------
# librolegen.a
# ------------------------------------------------------------------

STATICLIB			= $(OBJDIR)/librolegen.a

ISTATICLIB_OBJS		=
STATICLIB_OBJS 		+= $(OBJDIR)/rolegen.o


# ------------------------------------------------------------------
# tools
# ------------------------------------------------------------------

MKROLE				= $(OBJDIR)/mkls2role

MKROLE_OBJS			=
MKROLE_OBJS			= $(OBJDIR)/mkls2role.o

MKROLE_LIBS			=
MKROLE_LIBS			+= -lrolegen

MKROLE_LDFLAGS	=
MKROLE_LDFLAGS	+= -L$(OBJDIR)

# ------------------------------------------------------------------
# common
# ------------------------------------------------------------------

LOCAL_CFLAGS		+= -I$(INCLUDE_DIR)
LOCAL_CFLAGS		+= -Wall -fPIC -fvisibility=hidden

# ------------------------------------------------------------------
# build rules
# ------------------------------------------------------------------
all: setup $(STATICLIB) $(MKROLE)

setup:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CFLAGS) $(LOCAL_CFLAGS) -c $< -o $@

$(MKROLE): $(MKROLE_OBJS)
	$(CXX) $(MKROLE_LDFLAGS) $(LDFLAGS) -o $(MKROLE) $(MKROLE_OBJS)  $(MKROLE_LIBS)
	
$(STATICLIB) : $(STATICLIB_OBJS)
	$(AR) -rcs $(STATICLIB_LDFLAGS) $(STATICLIB) $(STATICLIB_OBJS)
	$(STRIP) --strip-unneeded $(STATICLIB)

	
clean:
	rm -rf $(OBJDIR)
	rm -f $(LUNA_STAGING)/include/rolegen.h
	
install:
	mkdir -p $(LUNA_STAGING)/include/rolegen
	mkdir -p $(LUNA_STAGING)/lib
	install -m 0644 rolegen.h $(LUNA_STAGING)/include/rolegen
	cd $(LUNA_STAGING)/include; ln -s rolegen/rolegen.h
	install -m 0755 $(STATICLIB) $(LUNA_STAGING)/lib

stage:
	echo "nothing to do"
		
