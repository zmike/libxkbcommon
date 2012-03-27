/************************************************************
 Copyright (c) 1994 by Silicon Graphics Computer Systems, Inc.

 Permission to use, copy, modify, and distribute this
 software and its documentation for any purpose and without
 fee is hereby granted, provided that the above copyright
 notice appear in all copies and that both that copyright
 notice and this permission notice appear in supporting
 documentation, and that the name of Silicon Graphics not be
 used in advertising or publicity pertaining to distribution
 of the software without specific prior written permission.
 Silicon Graphics makes no representation about the suitability
 of this software for any purpose. It is provided "as is"
 without any express or implied warranty.

 SILICON GRAPHICS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS
 SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL SILICON
 GRAPHICS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL
 DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  WITH
 THE USE OR PERFORMANCE OF THIS SOFTWARE.

 ********************************************************/

#ifndef XKBPARSE_H
#define	XKBPARSE_H 1

#include "xkbcomp.h"
#include "xkbparse.h"

struct parser_param {
    void *scanner;
    XkbFile *rtrn;
};

struct scanner_extra {
    char *scanFile;
    /* FIXME: This can overflow! */
    char scanBuf[8192];
    char *s;
};

extern ParseCommon *AppendStmt(ParseCommon * /* to */ ,
                               ParseCommon *    /* append */
    );

extern ExprDef *ExprCreate(unsigned /* op */ ,
                           unsigned     /* type */
    );

extern ExprDef *ExprCreateUnary(unsigned /* op */ ,
                                unsigned /* type */ ,
                                ExprDef *       /* child */
    );

extern ExprDef *ExprCreateBinary(unsigned /* op */ ,
                                 ExprDef * /* left */ ,
                                 ExprDef *      /* right */
    );

extern KeycodeDef *KeycodeCreate(char * /* name */ ,
                                 unsigned long /* value */
    );

extern KeyAliasDef *KeyAliasCreate(char * /* alias */ ,
                                   char *       /* real */
    );

extern VModDef *VModCreate(xkb_atom_t /* name */ ,
                           ExprDef *    /* value */
    );

extern VarDef *VarCreate(ExprDef * /* name */ ,
                         ExprDef *      /* value */
    );

extern VarDef *BoolVarCreate(xkb_atom_t /* nameToken */ ,
                             unsigned   /* set */
    );

extern InterpDef *InterpCreate(char * /* sym */ ,
                               ExprDef *        /* match */
    );

extern KeyTypeDef *KeyTypeCreate(xkb_atom_t /* name */ ,
                                 VarDef *       /* body */
    );

extern SymbolsDef *SymbolsCreate(char * /* keyName */ ,
                                 ExprDef *      /* symbols */
    );

extern GroupCompatDef *GroupCompatCreate(int /* group */ ,
                                         ExprDef *      /* def */
    );

extern ModMapDef *ModMapCreate(uint32_t /* modifier */ ,
                               ExprDef *        /* keys */
    );

extern IndicatorMapDef *IndicatorMapCreate(xkb_atom_t /* name */ ,
                                           VarDef *     /* body */
    );

extern IndicatorNameDef *IndicatorNameCreate(int /* ndx */ ,
                                             ExprDef * /* name */ ,
                                             Bool       /* virtual */
    );

extern ExprDef *ActionCreate(xkb_atom_t /* name */ ,
                             ExprDef *  /* args */
    );

extern ExprDef *CreateKeysymList(char * /* sym */
    );

extern ExprDef *AppendKeysymList(ExprDef * /* list */ ,
                                 char * /* sym */
    );

extern int LookupKeysym(char * /* str */ ,
                        xkb_keysym_t *        /* sym_rtrn */
    );

extern IncludeStmt *IncludeCreate(char * /* str */ ,
                                  unsigned      /* merge */
    );

extern unsigned StmtSetMerge(ParseCommon * /* stmt */ ,
                             unsigned   /* merge */,
                             YYLTYPE *  /* loc */,
                             void *     /* scanner */
    );

#ifdef DEBUG
extern void PrintStmtAddrs(ParseCommon *        /* stmt */
    );
#endif

extern int XKBParseFile(FILE * /* file */ ,
                        const char *    /* fileName */,
                        XkbFile **      /* pRtrn */
    );

extern int XKBParseString(const char *string, const char *fileName,
                          XkbFile ** pRtrn);

extern void CheckDefaultMap(XkbFile * maps, const char *fileName);

extern XkbFile *CreateXKBFile(int /* type */ ,
                              char * /* name */ ,
                              ParseCommon * /* defs */ ,
                              unsigned  /* flags */
    );

extern void FreeXKBFile(XkbFile *file);

extern void FreeStmt(ParseCommon * /* stmt */
    );

extern void yyerror(struct YYLTYPE *loc, void *scanner, const char *msg);

#endif /* XKBPARSE_H */
