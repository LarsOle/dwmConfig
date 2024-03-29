/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#111111";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#005577";
static const char selbgcolor[]      = "#111111";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool focusonwheelscroll = False;

/* tagging */
static const char *tags[] = { "www", "editor", "terminal", "misc", "skype"};

static const Rule rules[] = {
  /* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "Skype",	  NULL,		  NULL,       1 << 4,       False,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *volumeUp[] = { "/home/lars/bin/volume.sh", "-i", "5", NULL};
static const char *volumeDown[] = { "/home/lars/bin/volume.sh", "-d", "5", NULL};

static Key keys[] = {
	/* modifier                     key        				function        argument */
	{ MODKEY,                       XK_d,      				spawn,          {.v = dmenucmd } },
	{ MODKEY,             		XK_Return, 				spawn,          {.v = termcmd } },
	{ 0,				0x1008ff13,			 	spawn, 		{.v = volumeUp} },
	{ 0,				0x1008ff11, 				spawn, 		{.v = volumeDown} },
	{ MODKEY,                       XK_b,      				togglebar,      {0} },
	{ MODKEY,                       XK_j,      				focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      				focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,     				incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_g,      				incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      				setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      				setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Tab,    				view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      				killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_space,  				togglefloating, {0} },
	{ MODKEY,                       XK_0,      				view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      				tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  				focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 				focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_e,	   				tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 				tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      				0)
	TAGKEYS(                        XK_2,                      				1)
	TAGKEYS(                        XK_3,                      				2)
	TAGKEYS(                        XK_4,                      				3)
	TAGKEYS(                        XK_5,                      				4)
	{ MODKEY|ShiftMask,             XK_p,      				quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
