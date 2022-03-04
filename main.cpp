#include <EHS/EHS.h>
#include <EHS/Str.h>
#include <EHS/Log.h>
#include <EHS/Array.h>
#include <EHS/Vector.h>
#include <EHS/IO/MsgBox.h>
#include <EHS/IO/Console.h>

int main()
{
    if (!ehs::Console::Attach())
        ehs::Console::Create();

    ehs::Str_8 cmd = ehs::Console::GetCommandLine_8();

    ehs::USize s = 0;

    if (cmd.Find("  ", &s, ehs::SearchPattern::LEFT_RIGHT, ehs::IndexResult::ENDING))
    {
        ehs::Str_8 fullArgs = cmd.Sub(s);
        ehs::Vector<ehs::Str_8> args = fullArgs.Split(" ");
        for (ehs::USize i = 1; i < args.Size(); ++i)
            ehs::Console::Write_8("Result " + ehs::Str_8::FromNum(i) + ": " + ehs::Str_8::FromNum(args[i].Hash()));
    }
    else
    {
        ehs::Console::Write_8("String: ", false);
        ehs::Str_8 in = ehs::Console::Read_8();
        ehs::Console::Write_8("Result: " + ehs::Str_8::FromNum(in.Hash()));

        ehs::Console::Read_8();
    }

    ehs::Console::Free();

    return 0;
}
