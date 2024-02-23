#include <iostream>
#include <SOARE/SOARE.h>

/*!
 * Antoine LANDRIEUX
 * SOARE <https://github.com/AntoineLandrieux/SOARE>
 * 
 * GNU General Public License v3.0
 * https://www.gnu.org/licenses/
*/

/*
 * Your Function:

 // namespace externalfunction
 // {
 //    void System(char *_Cmd)
 //    {
 //       std::system(_Cmd);
 //   }
 //}
*/

static SOARE::TOKENS tokens = nullptr;

static void CMD()
{
    std::cout << "SOARE v" << SOARE_VERSION_MAJOR << "." << SOARE_VERSION_MINOR << "." << SOARE_VERSION_PATCH << " " << __DATE__ << " Antoine LANDRIEUX\n"
              << "(https://github.com/AntoineLandrieux/SOARE)\n"
              << std::endl;

    char user[SOARE_MAX_INPUT];

    while (true)
    {
        std::cout << "> ";

        if (std::cin.getline(user, sizeof(user)).eof())
            break;

        else if (user[0] == 0)
        {
            SOARE::resultlang_free(SOARE::ExecuteTokens(tokens));
            token_free(tokens);
            tokens = nullptr;
            continue;
        }

        tokens = SOARE::token_join(tokens, SOARE::Tokenizer(user));
    }
}

static void __attribute__((constructor)) config()
{
    /*
     * Add custom Executor
     // SOARE::AddCustomExecutor((char *)"OS", externalfunction::System);

     * Define argument
     // char *_Arg_OS_[] = {(char *)"$"};

     * Define function :
```
    FUNCTION ("OS")
    /       \
ARG ("$")   BODY
            /
    NODE CUSTOM ("OS")
        /
    VARIABLE ("$")
```

     // SOARE::SoareDefineFunction(SOARE::FunctionModel(
        // (char *)"OS", SOARE::ArgModel(1, _Arg_OS_),
        // SOARE::branch_push(
            // SOARE::branch((char *)"OS", SOARE::NODE_CUSTOM),
            // SOARE::branch(_Arg_OS_[0], SOARE::NODE_GET))));
    */
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        CMD();
    else SOARE::resultlang_free(SOARE::ExecuteTokens(SOARE::file_read(argv[1])));
    return EXIT_SUCCESS;
}

static void __attribute__((destructor)) kill()
{
    SOARE::branch_free(SOARE::SoareDefineFunction(NULL));
    SOARE::token_free(tokens);
}
