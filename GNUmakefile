CC = gcc
CFLAGS = -O2
CCLD = gcc
LDFLAGS = -s -Wl,--subsystem=windows \
		  -Wl,--nxcompat \
		  -Wl,--dynamicbase \
		  -Wl,--enable-auto-image-base
RC = windres
AR = ar
RM = rm

SRCDIR = Src
OUTDIR = GCCBuild
SHAREDLIB = $(OUTDIR)/WinDial.dll
IMPLIB = $(OUTDIR)/WinDial.dll.a
STATICLIB = $(OUTDIR)/WinDial.a
OBJS = $(OUTDIR)/WinDial.o
RES =  $(OUTDIR)/WinDial.res.o
LIBS= -lrasapi32

all: $(OUTDIR) $(SHAREDLIB) $(STATICLIB)

$(SHAREDLIB): $(OBJS) $(RES)
	$(CCLD) $(LDFLAGS) -shared \
		-Wl,--out-implib,$(IMPLIB) \
		-o $(SHAREDLIB) $(OBJS) $(RES) $(LIBS)

$(STATICLIB): $(OBJS)
	$(AR) crs $(STATICLIB) $(OBJS)

$(OUTDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUTDIR)/%.res.o: $(SRCDIR)/%.rc
	$(RC) -o $@ $<

$(OUTDIR):
	mkdir -p $(OUTDIR)

clean:
	$(RM) -rf $(OUTDIR)
