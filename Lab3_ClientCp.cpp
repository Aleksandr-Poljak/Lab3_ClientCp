#include <iostream>
#include <ole2.h>
#include <comutil.h> // Для VARIANT и BSTR

int main()
{
    HRESULT hr = OleInitialize(NULL);
    if (FAILED(hr))
    {
        std::wcerr << L"OLE initialization error: " << std::hex << hr << std::endl;
        return 1;
    }
    std::wcout << L"OLE initialized" << std::endl;

    wchar_t progid[] = L"Lb34MyFn.1";
    CLSID clsid;
    hr = ::CLSIDFromProgID(progid, &clsid);
    if (FAILED(hr))
    {
        std::wcerr << L"Error getting CLSID: " << std::hex << hr << std::endl;
        OleUninitialize();
        return 1;
    }
    std::wcout << L"Getting CLSID" << std::endl;

    // Создание экземпляра COM-объекта.
    IDispatch* pIDispatch = NULL;
    hr = ::CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&pIDispatch);
    if (FAILED(hr))
    {
        std::wcerr << L"Object creation error: " << std::hex << hr << std::endl;
        OleUninitialize();
        return 1;
    }
    std::wcout << L"Object creation" << std::endl;

    // Получение DISPID для метода Fun141.
    DISPID dispidFun141;
    OLECHAR* nameFun141 = (OLECHAR*)L"Fun141";
    hr = pIDispatch->GetIDsOfNames(IID_NULL, &nameFun141, 1, LOCALE_USER_DEFAULT, &dispidFun141);
    if (FAILED(hr))
    {
        std::wcerr << L"Error getting DISPID for Fun141: " << std::hex << hr << std::endl;
        pIDispatch->Release();
        OleUninitialize();
        return 1;
    }
    std::wcout << L"DISPID received for Fun141: "<< dispidFun141 << std::endl;
    

    // Получение DISPID для метода Fun142.
    DISPID dispidFun142;
    OLECHAR* nameFun142 = (OLECHAR*)L"Fun142";
    hr = pIDispatch->GetIDsOfNames(IID_NULL, &nameFun142, 1, LOCALE_USER_DEFAULT, &dispidFun142);
    if (FAILED(hr))
    {
        std::wcerr << L"Error getting DISPID for Fun142: " << std::hex << hr << std::endl;
        pIDispatch->Release();
        OleUninitialize();
        return 1;
    }
    std::wcout << L"DISPID received for Fun142: " << dispidFun142 << std::endl;

    // Получение DISPID для метода Fun143.
    DISPID dispidFun143;
    OLECHAR* nameFun143 = (OLECHAR*)L"Fun143";
    hr = pIDispatch->GetIDsOfNames(IID_NULL, &nameFun143, 1, LOCALE_USER_DEFAULT, &dispidFun143);
    if (FAILED(hr))
    {
        std::wcerr << L"Error getting DISPID for Fun143: " << std::hex << hr << std::endl;
        pIDispatch->Release();
        OleUninitialize();
        return 1;
    }
    std::wcout << L"DISPID received for Fun143: " << dispidFun143 << std::endl;

    // Подготовка параметров и вызов методов. 
    
    ////////Подготовка аргументов для Fun141(INT x, INT y, DOUBLE* z)//////////////////////////
    std::wcout << L"*******************************************************" << std::endl;
    VARIANT args[2];
    VariantInit(&args[0]);
    args[0].vt = VT_INT;
    args[0].intVal = 5; // x

    VariantInit(&args[1]);
    args[1].vt = VT_INT;
    args[1].intVal = 10; // y

    DISPPARAMS params = { args, NULL, 2, 0 };

    VARIANT result;
    VariantInit(&result);

    hr = pIDispatch->Invoke(dispidFun141, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &result, NULL, NULL);
    if (SUCCEEDED(hr))
    {
        // Проверка возвращаемого значения
        if (result.vt == VT_R8)
        {
            std::wcout << L"Result of Fun141: " << result.dblVal << std::endl;
        }
        else
        {
            std::wcerr << L"Unexpected result type: " << result.vt << std::endl;
        }
    }
    else
    {
        std::wcerr << L"Error invoking Fun141: " << std::hex << hr << std::endl;
    }

    // Освобождение ресурсов.
    VariantClear(&result);

    ////////Подготовка аргументов для Fun142(INT x, INT y, INT c,  DOUBLE* z)//////////////////////////
    VARIANT argsFun142[3];
    VariantInit(&argsFun142[0]);
    argsFun142[0].vt = VT_INT;
    argsFun142[0].intVal = 5; // x

    VariantInit(&argsFun142[1]);
    argsFun142[1].vt = VT_INT;
    argsFun142[1].intVal = 10; // y

    VariantInit(&argsFun142[2]);
    argsFun142[2].vt = VT_INT;
    argsFun142[2].intVal = 15; // c

    DISPPARAMS paramsFun142 = { argsFun142, NULL, 3, 0 };

    VARIANT resultFun142;

    hr = pIDispatch->Invoke(dispidFun142, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &paramsFun142, &resultFun142, NULL, NULL);
    if (SUCCEEDED(hr))
    {
        std::wcout << L"Result of Fun142: " << resultFun142.intVal << std::endl;
    }
    else
    {
        std::wcerr << L"Error invoking Fun142: " << std::hex << hr << std::endl;
    }
    VariantClear(&resultFun142);

    // Подготовка аргументов для Fun143
    VARIANT argsFun143[1];

    VariantInit(&argsFun143[0]);
    argsFun143[0].vt = VT_R8; 
    argsFun143[0].dblVal = 5.1;

    DISPPARAMS paramsFun143 = { argsFun143, NULL, 1, 0 };
    VARIANT resultFun143;

    hr = pIDispatch->Invoke(dispidFun143, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &paramsFun143, &resultFun143, NULL, NULL);

    if (SUCCEEDED(hr))
    {
        std::wcout << L"Result of Fun143 (out parameter): " << resultFun143.dblVal << std::endl;
    }
    else
    {
        std::wcerr << L"Error invoking Fun143: " << std::hex << hr << std::endl;
    }

    VariantClear(&argsFun143[0]);

    std::wcout << L"*******************************************************" << std::endl;
    pIDispatch->Release();
    std::wcout << L"Release pIDispatch " << std::endl;
    OleUninitialize();
    std::wcout << L"OLE unloaded" << std::endl;

    return 0;
}
